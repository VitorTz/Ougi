#include "Scene.hpp"


static og::Cube cube{ 20.f };

static double rotation{};


og::LevelScene::LevelScene() {
	cube.set_colors(
		{
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS),
			og::rand_choice(og::ALL_COLORS)
		}
	);
}


void og::LevelScene::update(const double dt) {
	rotation += dt * 40.0;
}


void og::LevelScene::draw() {
	glLoadIdentity();
	glTranslated(0.0, 0.0, -50.0);
	glRotated(rotation, 0.0, 1.0, 0.0);
	cube.draw();
}