#pragma once
#include <GLFW/glfw3.h>
#include "Color.hpp"
#include <memory>
#include <string>


namespace og {	


	void window_init();
	void window_mainloop();
	
	int window_width();
	int window_height();

	double window_get_deltatime();

	void window_set_background_color(const og::Color& color);
	const og::Color& window_get_background_color();

	bool is_key_pressed(const int key);

}