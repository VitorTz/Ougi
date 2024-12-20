#include <array>
#include <chrono>
#include <Windows.h>
#include <gl/GLU.h>
#include <iostream>
#include "Window.hpp"
#include "OugiConfig.hpp"
#include "Drawable.hpp"
#include "Vector.hpp"
#include "util.hpp"


// Window
static og::OugiWindow window{};


void og::window_init() {
	if (!glfwInit()) {
		std::exit(EXIT_FAILURE);
	}
	
	// Window Hints
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	// Create Window
	window.gl_window = glfwCreateWindow(og::config::DEFAULT_SCREEN_W, og::config::DEFAULT_SCREEN_H, og::config::WINDOW_TITLE, NULL, NULL);	

	if (!window.gl_window) {
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	// Center Window
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window.gl_window, mode->width / 2 - og::config::DEFAULT_SCREEN_W / 2, mode->height / 2 - og::config::DEFAULT_SCREEN_H / 2);

	// Context
	glfwMakeContextCurrent(window.gl_window);

	// Enable V-SYNC
	glfwSwapInterval(1);

	// Background color	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	
	// Mouse Callback
	glfwSetCursorPosCallback(window.gl_window, og::mouse_default_pos_callback);
	glfwSetMouseButtonCallback(window.gl_window, og::mouse_default_button_callback);
	glfwSetScrollCallback(window.gl_window, og::mouse_default_scroll_callback);

	// Key Callback
	glfwSetKeyCallback(window.gl_window, og::key_listener_key_callback);

	// Make window visible
	glfwShowWindow(window.gl_window);

	// Graphics card info
	std::cout << "Company: " << glGetString(GL_VENDOR) << '\n';
	std::cout << "Model: " << glGetString(GL_RENDERER) << '\n';
	std::cout << "OPENGL Version: " << glGetString(GL_VERSION) << '\n';
}


void og::window_close() {	
	glfwTerminate();
}


inline static void window_end_frame() {
	og::mouse_default_end_frame();
	og::key_listener_default_end_frame();
}


void og::window_mainloop() {
	
	og::Cube cube{ 20.f };

	cube.set_colors(
		{
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS)
		}
	);

	double rotation{};	
	while (!glfwWindowShouldClose(window.gl_window)) {
		const auto last_frame_time = std::chrono::system_clock::now();		
		rotation += window.dt * 40.0;
		
		// Check event
			glfwPollEvents();

		// update
			/*if (og::is_mouse_button_pressed(GLFW_MOUSE_BUTTON_1)) {
				cube.set_colors(
					{
						og::rand_choice(og::ALL_COLORS),
						og::rand_choice(og::ALL_COLORS),
						og::rand_choice(og::ALL_COLORS),
						og::rand_choice(og::ALL_COLORS),
						og::rand_choice(og::ALL_COLORS),
						og::rand_choice(og::ALL_COLORS)
					}
				);
			}*/			


		// Clear background and update viewport && perspective			
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			
			glfwGetFramebufferSize(window.gl_window, &window.width, &window.height);
			const float aspect = (float)window.width / (float)window.height;
			glViewport(0, 0, window.width, window.height);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45.0, aspect, 0.1, 500);
			glMatrixMode(GL_MODELVIEW);

		// Draw
			glLoadIdentity();
			glTranslated(0.0, 0.0, -50.0);
			glRotated(rotation, 1.0, 1.0, 0.0);
			cube.draw();

		// Display		
			glfwSwapBuffers(window.gl_window);

		// End frame
			window_end_frame();

		// Update dt		
			window.dt = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - last_frame_time).count() / 1000.0;
	}
}


inline int og::window_width() {
	return window.width;
}


inline int og::window_height() {
	return window.height;
}


inline double og::window_get_deltatime() {
	return window.dt;
}
