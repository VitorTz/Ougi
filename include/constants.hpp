#ifndef OUGI_CONSTANTS_HPP
#define OUGI_CONSTANTS_HPP
#include <SFML/System/Vector2.hpp>
#include <map>
#include <string>
#include "color.hpp"


namespace og {

    // screen
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const sf::Color SCREEN_COLOR = og::Color::Black;
    const std::string SCREEN_TITLE = "Ougi!";
    const std::string SCREEN_ICON = "res/icon/Ougi.png";
    const int FPS = 60;
    
    // keyboard
    const int KEYBOARD_STRING_VALUE_MAX_LENGTH = 256;
    

} // namespace og



#endif