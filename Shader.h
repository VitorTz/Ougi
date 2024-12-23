#pragma once
#include <vector>


namespace og {

	const char* get_default_vertex_shader();
	const char* get_default_fragment_shader();
	
	void shader_init_default_shader_program();
	unsigned int shader_get_default_shader_program();

	unsigned int shader_fragment_compile(const char* source);
	unsigned int shader_vertex_compile(const char* source);
	unsigned int shader_program_create(unsigned int vertex_shader, unsigned int fragment_shader);
	unsigned int shader_program_create(const std::vector<unsigned int>& shaders);
	unsigned int shader_program_create(const unsigned int* shaders, std::size_t num_shaders);

}