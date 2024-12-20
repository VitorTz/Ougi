#pragma once
#include <GLFW/glfw3.h>
#include <array>


namespace og {

	typedef struct key_listener {
		std::array<bool, GLFW_KEY_LAST + 1> pressed_keys{};
		void (*end_frame)();
	} KeyListener;

	
	const KeyListener* get_key_listener();	

	void key_listener_default_end_frame();

	bool is_key_pressed(int key);

}