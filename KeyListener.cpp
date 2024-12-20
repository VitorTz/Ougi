#include "KeyListener.hpp"


static og::KeyListener k_listener{};


const og::KeyListener* og::get_key_listener() {
	return &k_listener;
}


bool og::is_key_pressed(const int key) {
	return key <= GLFW_KEY_LAST && k_listener.pressed_keys[key];
}


void og::key_listener_default_end_frame() {
	for (bool& b : k_listener.pressed_keys) {
		b = false;
	}
}

