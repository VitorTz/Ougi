#include "KeyListener.hpp"
#include <cassert>


static og::KeyListener k_listener{};


const og::KeyListener* og::get_key_listener() {
	return &k_listener;
}


void og::key_listener_key_callback(
	GLFWwindow* window,
	const int key,
	const int scancode,
	const int action,
	const int mods
) {	
	const bool s = action == GLFW_PRESS;
	k_listener.down_keys[key] = s;
	k_listener.pressed_keys[key] = s;
}


bool og::key_listener_is_key_pressed(const int key) {
	assert(key <= GLFW_KEY_LAST && "INVALID KEYBOARD KEY!");
	return k_listener.pressed_keys[key];
}


bool og::key_listener_is_key_down(const int key) {
	assert(key <= GLFW_KEY_LAST && "INVALID KEYBOARD KEY!");
	return k_listener.down_keys[key];
}


void og::key_listener_default_end_frame() {
	for (bool& b : k_listener.pressed_keys) {
		b = false;
	}
}

