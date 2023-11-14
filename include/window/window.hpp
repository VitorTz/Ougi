#ifndef OUGI_WINDOW_HPP
#define OUGI_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../constants.hpp"
#include "../globals.hpp"
#include "../util/util.hpp"


namespace og {


    class Window {

        private:
            static Window* instance;
            Window();
        
        public:
            static Window* getInstance();
            ~Window();
        
        private:
            sf::RenderWindow window;
            sf::Clock clock;
        
        private:
            void initScreenIcon();
            void handleInput();
            void update();
            void draw();
        
        public:
            void run();

    };
    
} // namespace og



#endif