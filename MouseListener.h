#pragma once
#include <GLFW/glfw3.h>
#include "Vector.h"


namespace og {

	void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void mouse_end_frame();

	const og::Vector2d& mouse_get_pos();
	double mouse_get_posX();
	double mouse_get_posY();

	const og::Vector2d& mouse_get_scroll();
	double mouse_get_scrollX();
	double mouse_get_scrollY();

	const og::Vector2d& mouse_get_delta_pos();
	double mouse_get_delta_posX();
	double mouse_get_delta_posY();

	const og::Vector2d& mouse_get_last_pos();
	double mouse_get_last_posX();
	double mouse_get_last_posY();

	bool mouse_is_dragged();
	bool mouse_is_btn_pressed(int button);

}
