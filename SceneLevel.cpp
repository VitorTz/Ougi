#include "Scene.h"


static float vertices[] = {
	0.5f,  0.5f, 0.0f,  // top right
	0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left
};


static int indices[] = {
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};

static unsigned int VAO{}; // Vertex array object
static unsigned int VBO{}; // Vertex buffer object
static unsigned int EBO{}; // Element buffer object
static unsigned int shader_program{};
static bool init_status{};


og::LevelScene::LevelScene() {
	if (!init_status) {
		init_status = true;


		// VAO
		glGenVertexArrays(1, &VAO);	
		glBindVertexArray(VAO);

		// VBO
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// EBO
		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		shader_program = og::shader_get_default_shader_program();
	}
		
}


void og::LevelScene::update(const double dt) {

}


void og::LevelScene::draw() {
	glUseProgram(shader_program);
	glBindVertexArray(VAO);	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}