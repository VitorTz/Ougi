#pragma once
#include <GLFW/glfw3.h>
#include <memory>
#include <string>
#include <memory>
#include "MouseListener.hpp"
#include "KeyListener.hpp"
#include "Color.hpp"
#include "Vector.hpp"


namespace og {	

	typedef struct ougi_window {
		GLFWwindow* gl_window{};
		double dt{};
		int width{};
		int height{};
	} OugiWindow;

	void window_init();

	void window_close();
	
	void window_mainloop();
	
	int window_width();

	int window_height();	

	double window_get_deltatime();		


}