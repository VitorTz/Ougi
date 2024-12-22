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


	namespace color {

		constexpr og::Color Red{ 1.0f, 0.0f, 0.0f, 1.0f };
		constexpr og::Color Green{ 0.0f, 1.0f, 0.0f, 1.0f };
		constexpr og::Color Blue{ 0.0f, 0.0f, 1.0f, 1.0f };
		
		constexpr og::Color Black{ 0.0f, 0.0f, 0.0f, 1.0f };
		constexpr og::Color White{ 1.0f, 1.0f, 1.0f, 1.0f };

		constexpr og::Color Crimson{ 0xDC143C };
		constexpr og::Color Firebrick{ 0xB22222 };
		constexpr og::Color Salmon{ 0xFA8072 };
		constexpr og::Color LightCoral{ 0xF08080 };
		constexpr og::Color HotPink{ 0xFF69B4 };

		constexpr og::Color Coral{ 0xFF7F50 };
		constexpr og::Color DarkOrange{ 0xFF8C00 };
		constexpr og::Color PeachPuff{ 0xFFDAB9 };
		constexpr og::Color Tomato{ 0xFF6347 };
		constexpr og::Color PapayaWhip{ 0xFFEFD5 };

		constexpr og::Color Gold{ 0xFFD700 };
		constexpr og::Color Yellow{ 0xFFFF00 };
		constexpr og::Color Khaki{ 0xF0E68C };
		constexpr og::Color LemonChiffon{ 0xFFFACD };
		constexpr og::Color LightGoldenrodYellow{ 0xFAFAD2 };

		constexpr og::Color ForestGreen{ 0x228B22 };
		constexpr og::Color LimeGreen{ 0x32CD32 };
		constexpr og::Color MediumSpringGreen{ 0x00FA9A };
		constexpr og::Color SeaGreen{ 0x2E8B57 };
		constexpr og::Color MintCream{ 0xF5FFFA };

		constexpr og::Color RoyalBlue{ 0x4169E1 };
		constexpr og::Color DodgerBlue{ 0x1E90FF };
		constexpr og::Color SkyBlue{ 0x87CEEB };
		constexpr og::Color SteelBlue{ 0x4682B4 };
		constexpr og::Color PowderBlue{ 0xB0E0E6 };

		constexpr og::Color Indigo{ 0x4B0082 };
		constexpr og::Color MediumOrchid{ 0xBA55D3 };
		constexpr og::Color Plum{ 0xDDA0DD };
		constexpr og::Color Violet{ 0xEE82EE };
		constexpr og::Color Lavender{ 0xE6E6FA };

		constexpr og::Color SaddleBrown{ 0x8B4513 };
		constexpr og::Color SandyBrown{ 0xF4A460 };
		constexpr og::Color Peru{ 0xCD853F };
		constexpr og::Color RosyBrown{ 0xBC8F8F };
		constexpr og::Color Chocolate{ 0xD2691E };

		constexpr og::Color WhiteSmoke{ 0xF5F5F5 };
		constexpr og::Color GhostWhite{ 0xF8F8FF };
		constexpr og::Color Snow{ 0xFFFAFA };
		constexpr og::Color Ivory{ 0xFFFFF0 };
		constexpr og::Color Beige{ 0xF5F5DC };

		constexpr og::Color MidnightBlue{ 0x191970 };
		constexpr og::Color SlateGray{ 0x708090 };
		constexpr og::Color DarkOliveGreen{ 0x556B2F };
		constexpr og::Color DarkSlateBlue{ 0x483D8B };
		constexpr og::Color Maroon{ 0x800000 };

		constexpr og::Color Turquoise{ 0x40E0D0 };
		constexpr og::Color SpringGreen{ 0x00FF7F };
		constexpr og::Color DeepPink{ 0xFF1493 };
		constexpr og::Color Chartreuse{ 0x7FFF00 };
		constexpr og::Color Aqua{ 0x00FFFF };

		constexpr std::array<og::Color, 55> ALL_COLORS = {
			og::color::Red,
			og::color::Green,
			og::color::Blue,
			og::color::Black,
			og::color::White,
			og::color::Crimson,
			og::color::Firebrick,
			og::color::Salmon,
			og::color::LightCoral,
			og::color::HotPink,
			og::color::Coral,
			og::color::DarkOrange,
			og::color::PeachPuff,
			og::color::Tomato,
			og::color::PapayaWhip,
			og::color::Gold,
			og::color::Yellow,
			og::color::Khaki,
			og::color::LemonChiffon,
			og::color::LightGoldenrodYellow,
			og::color::ForestGreen,
			og::color::LimeGreen,
			og::color::MediumSpringGreen,
			og::color::SeaGreen,
			og::color::MintCream,
			og::color::RoyalBlue,
			og::color::DodgerBlue,
			og::color::SkyBlue,
			og::color::SteelBlue,
			og::color::PowderBlue,
			og::color::Indigo,
			og::color::MediumOrchid,
			og::color::Plum,
			og::color::Violet,
			og::color::Lavender,
			og::color::SaddleBrown,
			og::color::SandyBrown,
			og::color::Peru,
			og::color::RosyBrown,
			og::color::Chocolate,
			og::color::WhiteSmoke,
			og::color::GhostWhite,
			og::color::Snow,
			og::color::Ivory,
			og::color::Beige,
			og::color::MidnightBlue,
			og::color::SlateGray,
			og::color::DarkOliveGreen,
			og::color::DarkSlateBlue,
			og::color::Maroon,
			og::color::Turquoise,
			og::color::SpringGreen,
			og::color::DeepPink,
			og::color::Chartreuse,
			og::color::Aqua
		};

	}

}