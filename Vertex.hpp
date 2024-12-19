#pragma once


namespace og {

	class Vertex3f {

	public:
		float x{};
		float y{};
		float z{};

	public:
		Vertex3f() = default;
		Vertex3f(
			const float x,
			const float y,
			const float z
		) : x(x), y(y), z(z) { }
 
	};

}