#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "util.h"
#include "config.h"
#include "SceneID.h"


namespace og {

	class Scene {

	public:
		virtual ~Scene() = default;
		virtual void update(double dt) = 0;
		virtual void draw() = 0;

	};

	class LevelEditorScene : public og::Scene {

	public:
		LevelEditorScene();
		void update(double dt) override;
		void draw() override;

	};

	class LevelScene : public og::Scene {

	public:
		LevelScene();
		void update(double dt) override;
		void draw() override;

	};

	void scene_manager_init();
	void scene_manager_change_scene(og::SceneID scene_id);
	void scene_manager_update(double dt);
	void scene_manager_draw();

}