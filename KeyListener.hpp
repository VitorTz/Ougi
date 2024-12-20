#pragma once
#include <GLFW/glfw3.h>


namespace og {

	void key_listener_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	void key_listener_end_frame();

	bool key_listener_is_key_pressed(int key);

	bool key_listener_is_key_down(int key);

}