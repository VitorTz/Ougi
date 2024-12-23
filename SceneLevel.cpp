#include "Scene.h"


static float vertex_array[] = {
	0.5, -0.5, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f, // bottom right
	-0.5, 0.5, 0.0f,		0.0f, 1.0f, 0.0f, 1.0f, // top left
	0.5, 0.5, 0.0f,		    0.0f, 0.0f, 1.0f, 1.0f, // top right
	-0.5, -0.5, 0.0f,		1.0f, 1.0f, 0.0f, 1.0f  // bottom left
};


static int element_array[] = {
	2, 1, 0,
	0, 1, 3
};


og::LevelScene::LevelScene() {
	
}


void og::LevelScene::update(const double dt) {

}


void og::LevelScene::draw() {
	
}