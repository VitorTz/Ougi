#pragma once
#include <GLFW/glfw3.h>
#include <array>
#include "Vector.hpp"


namespace og {	

	typedef struct mouse_listener {
		og::Vector2d mouse_pos{};
		og::Vector2d mouse_scrool{};
		og::Vector2d mouse_delta_pos{};
		og::Vector2d mouse_last_pos{};
		std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> mouse_button_pressed{};
		bool mouse_dragging{};		
	} MouseListener;

	const MouseListener* get_mouse_listener();	

	void mouse_default_pos_callback(GLFWwindow* window, double xpos, double ypos);
	void mouse_default_button_callback(GLFWwindow* window, int button, int action, int mods);
	void mouse_default_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void mouse_default_end_frame();

	bool is_mouse_button_pressed(int button);

}