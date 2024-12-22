#include "Scene.h"
#include <memory>


static std::unique_ptr<og::Scene> scene{};
static og::SceneID current_scene_id{};
static og::SceneID next_scene_id{ og::config::MAIN_SCENE };
static bool should_change_scene{};


static void load_next_scene() {
	switch (next_scene_id) {
	case og::SceneID::LevelEditorSceneID:
		scene = std::make_unique<og::LevelEditorScene>();
		break;
	case og::SceneID::LevelSceneID:
		scene = std::make_unique<og::LevelScene>();
		break;
	default:
		break;
	}
	current_scene_id = next_scene_id;
}


void og::scene_manager_init() {
	load_next_scene();
}


void og::scene_manager_change_scene(const og::SceneID scene_id) {
	next_scene_id = scene_id;
	should_change_scene = true;
}


void og::scene_manager_update(const double dt) {
	scene->update(dt);
}


void og::scene_manager_draw() {
	scene->draw();
	if (should_change_scene) {
		load_next_scene();
		should_change_scene = false;
	}
}