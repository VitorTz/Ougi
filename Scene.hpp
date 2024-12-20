#pragma once


namespace og {

	class Scene {

	public:
		virtual ~Scene() = default;
		virtual void update(double dt) = 0;
		virtual void draw() = 0;

	};

}