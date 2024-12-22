#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <iostream>
#include "Scene.h"
#include "KeyListener.h"
#include "MouseListener.h"
#include "util.h"
#include "config.h"

 
int main() {
	if (!glfwInit()) {
		std::cerr << "Could not init glfw!";
		return EXIT_FAILURE;
	}

	// Hint
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);	

	// Create Window
	int window_width{ og::config::DEFAULT_SCREEN_W };
	int window_height{ og::config::DEFAULT_SCREEN_H };
	GLFWwindow* window = glfwCreateWindow(
		og::config::DEFAULT_SCREEN_W, 
		og::config::DEFAULT_SCREEN_H, 
		og::config::DEFAULT_WINDOW_TITLE, 
		NULL, 
		NULL
	);
	if (window == NULL) {
		std::cerr << "Could not create window!";
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	// Center Window
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(
		window, 
		mode->width / 2 - og::config::DEFAULT_SCREEN_W / 2, 
		mode->height / 2 - og::config::DEFAULT_SCREEN_H / 2
	);

	// Enable V-SYNC
	glfwSwapInterval(1);

	// Glad Init
	gladLoadGL();

	// Background color
	glClearColor(
		og::config::DEFAULT_WINDOW_BG_COLOR.r, 
		og::config::DEFAULT_WINDOW_BG_COLOR.g, 
		og::config::DEFAULT_WINDOW_BG_COLOR.b, 
		og::config::DEFAULT_WINDOW_BG_COLOR.a
	);

	glEnable(GL_DEPTH_TEST);

	// Mouse Callback
	glfwSetCursorPosCallback(window, og::mouse_pos_callback);
	glfwSetMouseButtonCallback(window, og::mouse_button_callback);
	glfwSetScrollCallback(window, og::mouse_scroll_callback);

	// Keyboard Callback
	glfwSetKeyCallback(window, og::key_listener_key_callback);

	// Make window visible
	glfwShowWindow(window);

	// Graphics card info
	std::cout << "Company: " << glGetString(GL_VENDOR) << '\n';
	std::cout << "Model: " << glGetString(GL_RENDERER) << '\n';
	std::cout << "OPENGL Version: " << glGetString(GL_VERSION) << '\n';

	// Init SceneManager
	og::scene_manager_init();

	// Mainloop
	double dt{};	
	auto begin_time = std::chrono::system_clock::now();
	auto end_time = std::chrono::system_clock::now();
	
	while (!glfwWindowShouldClose(window)) {
		// Check events
			glfwPollEvents();

		// Update
			og::scene_manager_update(dt);
			
		// Clear Background
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glfwGetFramebufferSize(window, &window_width, &window_height);
			const float aspect = (float)window_width / (float)window_height;
			glViewport(0, 0, window_width, window_height);		

		// Draw
			og::scene_manager_draw();

		// Display
			glfwSwapBuffers(window);

		// End frame
			og::mouse_end_frame();
			og::key_listener_end_frame();

		// dt
			end_time = std::chrono::system_clock::now();
			dt = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count() / 1000.0;
			begin_time = std::chrono::system_clock::now();
	}

	// Close
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}