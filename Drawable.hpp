#pragma once
#include <GLFW/glfw3.h>
#include <array>
#include <cassert>
#include "Side.hpp"
#include "Vector.hpp"
#include "Color.hpp"
#include "Vertex.hpp"


namespace og {

	class Drawable {

	protected:
		og::Color color{};

	public:
		Drawable() = default;
		Drawable(const og::Color& color) : color(color) { }
		virtual void draw() = 0;
		virtual const og::Color& get_color() const { return this->color; }
		virtual void set_color(const og::Color& color) { this->color = color; }

	};	

	template<std::size_t num_vertices, int primitive>
	class Polygon : public og::Drawable {

	private:		
		std::array<og::Vector3f, num_vertices> vertices{};		

	public:
		Polygon() = default;

		Polygon(const og::Color& color) : color(color) { }

		Polygon(
			const std::array<og::Vector3f, num_vertices>& vertices,
			const og::Color& color
		) : Drawable(color), vertices(vertices) { }		

		void set_vertex(const og::Vector3f& v, const int ivertex) {
			assert(ivertex >= 0 && ivertex < num_vertices);
			this->vertices[ivertex] = v;
		}

		void set_vertex(const float x, const float y, const float z, const int ivertex) {
			assert(ivertex >= 0 && ivertex < num_vertices);
			this->vertices[ivertex] = { x, y, z };
		}

		int get_num_vertices() const {
			return num_vertices;
		}

		const std::array<og::Vector3f, num_vertices>& get_vertices() const {
			return this->vertices;
		}

		void draw() override {
			glColor3f(this->color.r, this->color.g, this->color.b);
			glBegin(primitive);
				for (const og::Vector3f& v : this->vertices) {
					glVertex3f(v.x, v.y, v.z);
				}
			glEnd();
		}
		
	};

	typedef og::Polygon<3, GL_TRIANGLES> Triangle;
	
	typedef og::Polygon<4, GL_QUADS> Square;	

	class Cube : public og::Drawable {

	private:
		std::array<og::Vector3f, 8> vertices{};		
		std::array<og::Color, 6> side_color{};

	private:
		
		inline void draw_rect(
			const int p1, 
			const int p2, 
			const int p3, 
			const int p4, 
			const int c
		) {
			glColor3f(this->side_color[c].r, this->side_color[c].g, this->side_color[c].b);
			glBegin(GL_QUADS);				
				glVertex3f(this->vertices[p1].x, this->vertices[p1].y, this->vertices[p1].z);
				glVertex3f(this->vertices[p2].x, this->vertices[p2].y, this->vertices[p2].z);
				glVertex3f(this->vertices[p3].x, this->vertices[p3].y, this->vertices[p3].z);
				glVertex3f(this->vertices[p4].x, this->vertices[p4].y, this->vertices[p4].z);
			glEnd();
		}

	public:
		Cube() = default;

		Cube(const float side) {
			const float d = side / 2.0f;
			this->vertices[0] = { -d, d, d };
			this->vertices[1] = { -d, -d, d };
			this->vertices[2] = { d, -d, d };
			this->vertices[3] = { d, d, d };

			this->vertices[4] = { d, d, -d };
			this->vertices[5] = { d, -d, -d };
			this->vertices[6] = { -d, -d, -d };
			this->vertices[7] = { -d, d, -d };
		}

		Cube(const float side, const og::Color& color) : Cube(side) {
			this->set_color(color);			
		}

		void set_color(const og::Color& color) override {
			for (og::Color& c : this->side_color) {
				c = color;
			}			
		}
		
		void set_colors(const og::Color colors[6]) {			
			for (int i = 0; i < 6; i++) {
				this->side_color[i] = colors[i];
			}
		}

		void set_colors(const std::array<og::Color, 6>& colors) {
			this->side_color = colors;
		}

		void set_vertice(const og::Vector3f& vertex, const int ivertex) {
			this->vertices[ivertex] = vertex;
		}

		void set_side_color(const og::Color& color, const og::Side side) {
			this->side_color[side] = color;
		}

		const og::Color& get_side_color(const og::Side side) { 
			return this->side_color[side];
		}

		void draw() override {
			this->draw_rect(0, 1, 2, 3, og::Front);
			this->draw_rect(3, 2, 5, 4, og::Right);			
			this->draw_rect(4, 7, 6, 5, og::Back);
			this->draw_rect(0, 7, 6, 1, og::Left);
			this->draw_rect(0, 3, 4, 7, og::Top);
			this->draw_rect(1, 6, 5, 2, og::Bottom);
		}

	};

}