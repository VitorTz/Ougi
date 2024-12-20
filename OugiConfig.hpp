#pragma once
#include "SceneID.hpp"


namespace og {

	namespace config {

		constexpr int DEFAULT_SCREEN_W{ 1280 };
		constexpr int DEFAULT_SCREEN_H{ 720 };
		constexpr char WINDOW_TITLE[]{ "Ougi" };
		
		constexpr og::SceneID MAIN_SCENE{ og::LevelSceneID };

	}

}