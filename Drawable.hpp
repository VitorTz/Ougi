#pragma once
#include <GLFW/glfw3.h>
#include <array>
#include <cassert>
#include "Color.hpp"
#include "Vertex.hpp"


namespace og {

	class Drawable {

	public:
		virtual void draw() = 0;

	};

	template<std::size_t num_vertices, int primitive>
	class Polygon : public og::Drawable {

	private:		
		std::array<og::Vertex3f, num_vertices> vertices{};
		og::Color color{};

	public:
		Polygon() = default;

		Polygon(const og::Color& color) : color(color) { }

		Polygon(
			const std::array<og::Vertex3f, num_vertices>& vertices,
			const og::Color& color
		) : vertices(vertices), color(color) { }

		void set_color(const og::Color& color) { this->color = color; }

		const og::Color& get_color() const { return this->color; }

		void set_vertex(const og::Vertex3f& v, const int ivertex) {
			assert(ivertex >= 0 && ivertex < num_vertices);
			this->vertices[ivertex] = v;
		}

		void set_vertex(const float x, const float y, const float z, const int ivertex) {
			assert(ivertex >= 0 && ivertex < num_vertices);
			this->vertices[ivertex] = og::Vertex3f{ x, y, z };
		}

		int get_num_vertices() const {
			return num_vertices;
		}

		const std::array<og::Vertex3f, num_vertices>& get_vertices() const {
			return this->vertices;
		}

		void draw() override {
			glColor3f(this->color.r, this->color.g, this->color.b);
			glBegin(primitive);
				for (og::Vertex3f& v : this->vertices) {
					glVertex3f(v.x, v.y, v.z);
				}
			glEnd();
		}
		
	};

	typedef og::Polygon<3, GL_TRIANGLES> Triangle;
	
	typedef og::Polygon<4, GL_QUADS> Square;

}