#pragma once
#include "SceneID.h"
#include "Color.h"


namespace og {

	namespace config {

		constexpr int DEFAULT_SCREEN_W{ 1280 };
		constexpr int DEFAULT_SCREEN_H{ 720 };
		constexpr char DEFAULT_WINDOW_TITLE[]{ "Ougi" };
		constexpr og::Color DEFAULT_WINDOW_BG_COLOR{ og::color::Black };
		constexpr og::SceneID MAIN_SCENE{ og::LevelSceneID };

	}

}