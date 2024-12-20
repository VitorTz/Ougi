#include <array>
#include <chrono>
#include <iostream>
#include "Window.hpp"
#include "Scene.hpp"
#include "MouseListener.hpp"
#include "KeyListener.hpp"
#include "OugiConfig.hpp"


static GLFWwindow* gl_window{};
static double window_dt{};
static int window_width{};
static int window_height{};


void og::window_init() {
	// Init GLFW
	if (!glfwInit()) {
		std::exit(EXIT_FAILURE);
	}
	
	// Window Hints
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	// Create Window
	gl_window = glfwCreateWindow(og::config::DEFAULT_SCREEN_W, og::config::DEFAULT_SCREEN_H, og::config::WINDOW_TITLE, NULL, NULL);	

	if (!gl_window) {
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	// Center Window
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(gl_window, mode->width / 2 - og::config::DEFAULT_SCREEN_W / 2, mode->height / 2 - og::config::DEFAULT_SCREEN_H / 2);

	// Context
	glfwMakeContextCurrent(gl_window);

	// Enable V-SYNC
	glfwSwapInterval(1);

	// Background color	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	
	// Mouse Callback
	glfwSetCursorPosCallback(gl_window, og::mouse_pos_callback);
	glfwSetMouseButtonCallback(gl_window, og::mouse_button_callback);
	glfwSetScrollCallback(gl_window, og::mouse_scroll_callback);

	// Key Callback
	glfwSetKeyCallback(gl_window, og::key_listener_key_callback);

	// Make window visible
	glfwShowWindow(gl_window);

	// Graphics card info
	std::cout << "Company: " << glGetString(GL_VENDOR) << '\n';
	std::cout << "Model: " << glGetString(GL_RENDERER) << '\n';
	std::cout << "OPENGL Version: " << glGetString(GL_VERSION) << '\n';

	// SceneManager
	og::scene_manager_init();
}


void og::window_close() {	
	glfwTerminate();
}


void og::window_run() {
	auto begin_time = std::chrono::system_clock::now();
	auto end_time = std::chrono::system_clock::now();

	while (!glfwWindowShouldClose(gl_window)) {
		// Check event
			glfwPollEvents();

		// update
			og::scene_manager_update(window_dt);

		// Clear background and update viewport && perspective			
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			
			glfwGetFramebufferSize(gl_window, &window_width, &window_height);
			const float aspect = (float)window_width/ (float)window_height;
			glViewport(0, 0, window_width, window_height);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45.0, aspect, 0.1, 500);
			glMatrixMode(GL_MODELVIEW);

		// Draw
			og::scene_manager_draw();

		// Display		
			glfwSwapBuffers(gl_window);

		// End frame
			og::mouse_end_frame();
			og::key_listener_end_frame();

		// Update dt
			end_time = std::chrono::system_clock::now();
			window_dt = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count() / 1000.0;
			begin_time = std::chrono::system_clock::now();
	}
}


int og::window_get_width() {
	return window_width;
}


int og::window_get_height() {
	return window_height;
}


double og::window_get_dt() {
	return window_dt;
}
