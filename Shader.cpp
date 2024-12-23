#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


static unsigned int default_shader_program{};


static const char* DEFAULT_VERTEX_SHADER = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";


static const char* DEFAULT_FRAGMENT_SHADER = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
	"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";


const char* og::get_default_vertex_shader() {
	return DEFAULT_VERTEX_SHADER;
}


const char* og::get_default_fragment_shader() {
	return DEFAULT_FRAGMENT_SHADER;
}


unsigned int og::shader_fragment_compile(const char* source) {
	int success{};
	char infoLog[512];

	// Create Fragment shader
	const unsigned int shader_id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader_id, 1, &source, NULL);

	// Compile
	glCompileShader(shader_id);

	// Check for compile errors
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader_id, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << '\n';
	}
	
	return shader_id;
}

unsigned int og::shader_vertex_compile(const char* source) {
	int success{};
	char infoLog[512];

	// Create Vertex Shader
	const unsigned int shader_id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader_id, 1, &source, NULL);

	// Compile
	glCompileShader(shader_id);

	// Check for compile erros
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader_id, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << '\n';
	}
	
	return shader_id;
}


unsigned int og::shader_program_create(const std::vector<unsigned int>& shaders) {
	int success{};
	char infoLog[512];

	// Create shader program
	const unsigned int shader_program = glCreateProgram();

	// Attach shaders to shader program
	for (const unsigned int shader : shaders) {
		glAttachShader(shader_program, shader);
	}

	// Linking
	glLinkProgram(shader_program);
	
	// Check if linking a shader program failed
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << '\n';
	}

	// Delete shaders objects
	for (const unsigned int shader : shaders) {
		glDeleteShader(shader);
	}	

	return shader_program;
}

unsigned int og::shader_program_create(
	const unsigned int* shaders,
	const std::size_t num_shaders
) {
	std::vector<unsigned int> shader_vec{};
	for (std::size_t i = 0; i < num_shaders; i++) {
		shader_vec.push_back(shaders[i]);
	}
	return og::shader_program_create(shader_vec);
}

unsigned int og::shader_program_create(
	const unsigned int vertex_shader, 
	const unsigned int fragment_shader
) {
	std::vector<unsigned int> shader_vec{};
	shader_vec.push_back(vertex_shader);
	shader_vec.push_back(fragment_shader);
	return og::shader_program_create(shader_vec);
}


void og::shader_init_default_shader_program() {
	const unsigned int v = og::shader_vertex_compile(DEFAULT_VERTEX_SHADER);
	const unsigned int f = og::shader_fragment_compile(DEFAULT_FRAGMENT_SHADER);	
	default_shader_program = og::shader_program_create(v, f);
}


unsigned int og::shader_get_default_shader_program() {
	return default_shader_program;
}