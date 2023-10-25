#pragma once
#ifndef OUGI_KEYBOARD_HPP
#define OUGI_KEYBOARD_HPP
#include <SFML/Graphics.hpp>
#include <iostream>


namespace og {

    class Keyboard {

        private:
            static Keyboard* instance;
            Keyboard();
        
        public:
            static Keyboard* getInstance();
            ~Keyboard();
        
        private:
            bool keys[256];
            bool keysLock[256];
        
        public:
            void update();
            void pressKey(const sf::Keyboard::Key& k);
            void releaseKey(const sf::Keyboard::Key& k);
            bool isPressed(const sf::Keyboard::Key& k);

    }; 
    
} // namespace og


#endif