#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Scene.h"
#include "Shader.h"
#include "KeyListener.h"
#include "MouseListener.h"
#include "util.h"
#include "config.h"


static float aspect{ og::config::DEFAULT_SCREEN_W / og::config::DEFAULT_SCREEN_H };


static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	aspect = (float) width / (float)height;
}

 
int main() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW!";
		return EXIT_FAILURE;
	}

	// Hint	
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
		std::cerr << "Failed to create GLFW window!";
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
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD";
		glfwDestroyWindow(window);
		glfwTerminate();
		return EXIT_FAILURE;
	}	

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

	// ViewPort Callback
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	// Make window visible
	glfwShowWindow(window);

	// Default Shader Program
	og::shader_init_default_shader_program();

	// Graphics card info
	std::cout << "Company: " << glGetString(GL_VENDOR) << '\n';
	std::cout << "Model: " << glGetString(GL_RENDERER) << '\n';
	std::cout << "OPENGL Version: " << glGetString(GL_VERSION) << '\n';

	// Init SceneManager
	og::scene_manager_init();

	// dt
	double dt{};
	double begin_time = glfwGetTime();
	double end_time{ begin_time };
	
	// Render loop
	while (!glfwWindowShouldClose(window)) {
		// Update
			og::scene_manager_update(dt);
			
		// Clear Background
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			

		// Draw
			og::scene_manager_draw();

		// Check events
			glfwPollEvents();

		// Display
			glfwSwapBuffers(window);

		// End frame
			og::mouse_end_frame();
			og::key_listener_end_frame();

		// dt
			end_time = glfwGetTime();
			dt = end_time - begin_time;
			begin_time = glfwGetTime();			
	}

	// Close
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}