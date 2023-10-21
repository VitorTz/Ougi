#ifndef CPP_GAME_CONSTANTS_HPP
#define CPP_GAME_CONSTANTS_HPP
#include <SFML/Graphics.hpp>
#include <string>


namespace og {

    // window
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const sf::Vector2f screenSize(screenWidth, screenHeight);
    const sf::Vector2f screenCenter(screenWidth / 2, screenHeight / 2);
    const std::string screenTitle = "Game!";
    const int screenFps = 60;

    // color
    const sf::Color windowBgColor = sf::Color::Black;

    // res
    const std::string icon = "res/icon/gamepad.png";

    // enum 
    enum class SceneId {
        Level
    };
    
} // namespace og



#endif