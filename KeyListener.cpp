#include "KeyListener.h"
#include <array>
#include <cassert>


static std::array<bool, GLFW_KEY_LAST + 1> down_keys{};
static std::array<bool, GLFW_KEY_LAST + 1> pressed_keys{};


void og::key_listener_key_callback(
	GLFWwindow* window,
	const int key,
	const int scancode,
	const int action,
	const int mods
) {
	assert(key <= GLFW_KEY_LAST && "INVALID KEYBOARD KEY!");
	const bool s = action == GLFW_PRESS;
	down_keys[key] = s;
	pressed_keys[key] = s;
}


bool og::key_listener_is_key_pressed(const int key) {
	assert(key <= GLFW_KEY_LAST && "INVALID KEYBOARD KEY!");
	return pressed_keys[key];
}


bool og::key_listener_is_key_down(const int key) {
	assert(key <= GLFW_KEY_LAST && "INVALID KEYBOARD KEY!");
	return down_keys[key];
}


void og::key_listener_end_frame() {
	for (bool& b : pressed_keys) {
		b = false;
	}
}