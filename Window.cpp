#include <Windows.h>
#include "Window.hpp"
#include "Drawable.hpp"
#include <gl/GLU.h>
#include <chrono>
#include <iostream>
#include "util.hpp"


static GLFWwindow* gl_window{};
static og::Color background_color{};
static int window_w{ 1280 };
static int window_h{ 720 };
static const char window_title[]{ "Ougi" };
static double dt{};



static void window_resize() {
	const float aspect = (float) window_w / (float)window_h ;
	glViewport(0, 0, window_w, window_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.1, 500);	
	glMatrixMode(GL_MODELVIEW);
}


void og::window_init() {
	if (!glfwInit()) {
		std::exit(EXIT_FAILURE);
	}

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	gl_window = glfwCreateWindow(window_w, window_h, window_title, NULL, NULL);

	if (!gl_window) {
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	// Center Window
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(gl_window, mode->width / 2 - window_w / 2, mode->height / 2 - window_h / 2);

	// Context
	glfwMakeContextCurrent(gl_window);

	// Enable V-SYNC
	glfwSwapInterval(1);

	// Background color	
	glClearColor(background_color.r, background_color.g, background_color.b, background_color.a);

	glfwShowWindow(gl_window);

	std::cout << "Company: " << glGetString(GL_VENDOR) << '\n';
	std::cout << "Model: " << glGetString(GL_RENDERER) << '\n';
	std::cout << "OPENGL Version: " << glGetString(GL_VERSION) << '\n';
}

void og::window_mainloop() {
	
	og::Square square{
		{
			og::Vertex3f{-2.5f, -2.5f, 0.0f},
			og::Vertex3f{2.5f, -2.5f, 0.0f},
			og::Vertex3f{2.5f, 2.5f, 0.0f},
			og::Vertex3f{-2.5f, 2.5f, 0.0f}
		},
		og::rand_choice(og::ALL_COLORS)
	};
	
	double rotation{ 0.0 };
	while (!glfwWindowShouldClose(gl_window)) {
		auto last_frame_time = std::chrono::system_clock::now();
		rotation -= dt * 100.0;
		/* Poll for and process events */
		glfwPollEvents();

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(gl_window, &window_w, &window_h);
		window_resize();

		glLoadIdentity();
		glTranslated(0.0, 0.0, -50.0);
		glRotated(rotation, 1.0, 1.0, 1.0);
		square.draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(gl_window);
		// Get the current time from the system clock		
		dt = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - last_frame_time).count() / 1000.0;
	}

	glfwTerminate();
}


bool og::is_key_pressed(const int key) {
	return glfwGetKey(gl_window, key);
}


void og::window_set_background_color(const og::Color& color) {
	background_color = color;
	glClearColor(color.r, color.g, color.b, color.a);
}

const og::Color& og::window_get_background_color() {
	return background_color;
}


int og::window_width() {
	return window_w;
}


int og::window_height() {
	return window_h;
}


double og::window_get_deltatime() {
	return dt;
}