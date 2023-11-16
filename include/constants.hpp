#ifndef OUGI_CONSTANTS_HPP
#define OUGI_CONSTANTS_HPP
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <map>
#include <string>


namespace og {

    // colors
    namespace Color {

        const sf::Color Black(0, 0, 0);
        const sf::Color Grey200(41, 42, 43);
        const sf::Color Grey400(51, 52, 53);
        
    } // namespace Color
    

    // screen
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Color SCREEN_COLOR = og::Color::Black;
    const std::string SCREEN_TITLE = "Ougi!";
    const std::string SCREEN_ICON = "res/icon/Ougi.png";
    const int FPS = 60;
    
    // keyboard
    const int KEYBOARD_STRING_VALUE_MAX_LENGTH = 256;
    
    // enum
    enum class SceneId {
        Level
    };

    const og::SceneId firstScene = og::SceneId::Level;
    

} // namespace og



#endif