#pragma once
#include <GLFW/glfw3.h>
#include <array>


namespace og {

	typedef struct key_listener {
		std::array<bool, GLFW_KEY_LAST + 1> down_keys{};
		std::array<bool, GLFW_KEY_LAST + 1> pressed_keys{};		
	} KeyListener;

	
	const KeyListener* get_key_listener();	

	void key_listener_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	void key_listener_default_end_frame();

	bool key_listener_is_key_pressed(int key);

	bool key_listener_is_key_down(int key);

}