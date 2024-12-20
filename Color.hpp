#pragma once 
#include <array>


namespace og {

	class Color {

	public:
		float r{};
		float g{};
		float b{};
		float a{};

	public:

		constexpr Color() : Color(0.0f, 0.0f, 0.0f, 1.0f) { }
		
		constexpr Color(
			const int hex
		) : r(static_cast<float>((hex & 0xFF000000) >> 24) / 255.0f),
			g(static_cast<float>((hex & 0x00FF0000) >> 16) / 255.0f),
			b(static_cast<float>((hex & 0x0000FF00) >> 8) / 255.0f),
			a(static_cast<float>((hex & 0x000000FF) >> 4) / 255.0f) { }
		
		constexpr Color(
			const int r, 
			const int g, 
			const int b, 
			const int a
		) : r(static_cast<float>(r) / 255.0f),
			g(static_cast<float>(g) / 255.0f), 
			b(static_cast<float>(b) / 255.0f), 
			a(static_cast<float>(a) / 255.0f) { }

		constexpr Color(
			const float r,
			const float g,
			const float b,
			const float a
		) : r(r),
			g(g), 
			b(b), 
			a(a) { }

	};

	constexpr og::Color RED{ 1.0f, 0.0f, 0.0f, 1.0f };
	constexpr og::Color GREEN{ 0.0f, 1.0f, 0.0f, 1.0f };
	constexpr og::Color BLUE{ 0.0f, 0.0f, 1.0f, 1.0f };
	constexpr og::Color DARK_TEAL{ 0x1A535C };
	constexpr og::Color MINT_GREEN{ 0x4ECDC4 };
	constexpr og::Color SOFT_WHITE{ 0xF7FFF7 };
	constexpr og::Color CORAL_RED{ 0xFF6B6B };
	constexpr og::Color LEMON_YELLOW{ 0xFFE66D };
	constexpr og::Color DEEP_CHARCOAL{ 0x2B2D42 };
	constexpr og::Color MUTED_BLUE_GRAY{ 0x8D99AE };
	constexpr og::Color PALE_GRAY{ 0xEDF2F4 };
	constexpr og::Color CRIMSON{ 0xEF233C };
	constexpr og::Color SCARLET{ 0xD90429 };
	constexpr og::Color RICH_PURPLE{ 0x6A0572 };
	constexpr og::Color BRIGHT_PINK{ 0xFF6F91 };
	constexpr og::Color WARM_GOLD{ 0xFFC15E };
	constexpr og::Color TURQUOISE{ 0x2EC4B6 };
	constexpr og::Color TANGERINE{ 0xFF9F1C };
	constexpr og::Color LIME_GREEN{ 0x8AC926 };
	constexpr og::Color VIBRANT_BLUE{ 0x1982C4 };
	constexpr og::Color ROYAL_PURPLE{ 0x6A4C93 };
	constexpr og::Color MIDNIGHT_BLUE{ 0x14213D };
	constexpr og::Color BOLD_RED{ 0xE63946 };

	constexpr std::array<og::Color, 23> ALL_COLORS = {
		og::RED,
		og::GREEN,
		og::BLUE,
		og::DARK_TEAL,
		og::MINT_GREEN,
		og::SOFT_WHITE,
		og::CORAL_RED,
		og::LEMON_YELLOW,
		og::DEEP_CHARCOAL,
		og::MUTED_BLUE_GRAY,
		og::PALE_GRAY,
		og::CRIMSON,
		og::SCARLET,
		og::RICH_PURPLE,
		og::BRIGHT_PINK,
		og::WARM_GOLD,
		og::TURQUOISE,
		og::TANGERINE,
		og::LIME_GREEN,
		og::VIBRANT_BLUE,
		og::ROYAL_PURPLE,
		og::MIDNIGHT_BLUE,
		og::BOLD_RED
	};

}