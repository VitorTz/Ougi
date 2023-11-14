#ifndef OUGI_CONSTANTS_HPP
#define OUGI_CONSTANTS_HPP
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>


namespace og {


    namespace Color {

        const sf::Color Black(0, 0, 0);
        const sf::Color Grey200(41, 42, 43);
        const sf::Color Grey400(51, 52, 53);
        
    } // namespace Color
    

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Color SCREEN_COLOR = og::Color::Black;
    const std::string SCREEN_TITLE = "Ougi!";
    const std::string SCREEN_ICON = "res/icon/Ougi.png";
    const int FPS = 60;
    

} // namespace og



#endif