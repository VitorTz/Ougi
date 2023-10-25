#pragma once
#ifndef OUGI_MOUSE_HPP
#define OUGI_MOUSE_HPP
#include <SFML/Graphics.hpp>


namespace og {


    class Mouse {

        private:
            static Mouse* instance;
            Mouse();
        
        public:
            static Mouse* getInstance();
            ~Mouse();
        
        private:
            sf::Vector2i mousePos;
            std::pair<bool, bool> leftBtn;
            std::pair<bool, bool> rightBtn;
            void updateBtnStatus(std::pair<bool, bool>& btn, bool status);
        
        public:
            void update(sf::RenderWindow& window);
            const sf::Vector2i& getMousePos();
            bool leftBtnIsPressed();
            bool rightBtnIsPressed();


    };
    
} // namespace og


#endif