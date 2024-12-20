#pragma once
#include "Platform.hpp"


namespace og {

	namespace config {

		constexpr int DEFAULT_SCREEN_W{ 1280 };
		constexpr int DEFAULT_SCREEN_H{ 720 };
		constexpr char WINDOW_TITLE[]{ "Ougi" };

		constexpr og::Platform PLATFORM{ og::Desktop };

	}

}