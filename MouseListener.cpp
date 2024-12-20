#include "MouseListener.hpp"


static og::MouseListener m_listener{};


const og::MouseListener* og::get_mouse_listener() {
	return &m_listener;
}


void og::mouse_default_pos_callback(
	GLFWwindow* window, 
	const double xpos,
	const double ypos
) {
	m_listener.mouse_last_pos = m_listener.mouse_pos;
	m_listener.mouse_pos = { xpos, ypos };
	m_listener.mouse_delta_pos = m_listener.mouse_pos - m_listener.mouse_last_pos;
	for (bool& b : m_listener.mouse_button_pressed) {
		if (b) {
			m_listener.mouse_dragging = true;
			break;
		}
	}
}


void og::mouse_default_button_callback(
	GLFWwindow* window, 
	const int button, 
	const int action, 
	const int mods
) {
	if (button > GLFW_MOUSE_BUTTON_LAST) { return; }
	m_listener.mouse_button_pressed[button] = action == GLFW_PRESS;
	m_listener.mouse_dragging = action == GLFW_RELEASE ? false : m_listener.mouse_dragging;
}


void og::mouse_default_scroll_callback(GLFWwindow* window, const double xoffset, const double yoffset) {
	m_listener.mouse_scrool = { xoffset, yoffset };
}


void og::mouse_default_end_frame() {
	m_listener.mouse_scrool = { 0.0, 0.0 };
	m_listener.mouse_last_pos = m_listener.mouse_pos;
}


bool og::is_mouse_button_pressed(const int button) {
	return button <= GLFW_MOUSE_BUTTON_LAST && m_listener.mouse_button_pressed[button];
}