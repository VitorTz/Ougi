#include "MouseListener.h"
#include <array>
#include <cassert>


static og::Vector2d mouse_pos{};
static og::Vector2d mouse_scrool{};
static og::Vector2d mouse_delta_pos{};
static og::Vector2d mouse_last_pos{};
static std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> mouse_button_pressed{};
static bool is_mouse_dragged{};


void og::mouse_pos_callback(GLFWwindow* window, const double xpos, const double ypos) {
	mouse_last_pos = mouse_pos;
	mouse_pos = { xpos, ypos };
	mouse_delta_pos = mouse_pos - mouse_last_pos;
	for (bool& b : mouse_button_pressed) {
		if (b) {
			is_mouse_dragged = true;
			break;
		}
	}
}


void og::mouse_button_callback(
	GLFWwindow* window,
	const int button,
	const int action,
	const int mods
) {
	assert(button <= GLFW_MOUSE_BUTTON_LAST);
	mouse_button_pressed[button] = action == GLFW_PRESS;
	is_mouse_dragged = action == GLFW_RELEASE ? false : is_mouse_dragged;
}


void og::mouse_scroll_callback(GLFWwindow* window, const double xoffset, const double yoffset) {
	mouse_scrool = { xoffset, yoffset };
}


void og::mouse_end_frame() {
	mouse_scrool = { 0.0, 0.0 };
	mouse_last_pos = mouse_pos;
}


bool og::mouse_is_btn_pressed(const int button) {
	assert(button <= GLFW_MOUSE_BUTTON_LAST);
	return mouse_button_pressed[button];
}


const og::Vector2d& og::mouse_get_pos() {
	return mouse_pos;
}

double og::mouse_get_posX() {
	return mouse_pos.x;
}


double og::mouse_get_posY() {
	return mouse_pos.y;
}


const og::Vector2d& og::mouse_get_scroll() {
	return mouse_scrool;
}


double og::mouse_get_scrollX() {
	return mouse_scrool.x;
}


double og::mouse_get_scrollY() {
	return mouse_scrool.y;
}


const og::Vector2d& og::mouse_get_delta_pos() {
	return mouse_delta_pos;
}


double og::mouse_get_delta_posX() {
	return mouse_delta_pos.x;
}


double og::mouse_get_delta_posY() {
	return mouse_delta_pos.y;
}


const og::Vector2d& og::mouse_get_last_pos() {
	return mouse_last_pos;
}


double og::mouse_get_last_posX() {
	return mouse_last_pos.x;
}


double og::mouse_get_last_posY() {
	return mouse_last_pos.y;
}


bool og::mouse_is_dragged() {
	return is_mouse_dragged;
}