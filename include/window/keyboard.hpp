#ifndef OUGI_GE_KEYBOARD_HPP
#define OUGI_GE_KEYBOARD_HPP
#include <SFML/Graphics.hpp>
#include <iostream>


namespace og {


    class Keyboard {

        public:
            static Keyboard* getInstance();
        
        public:
            ~Keyboard();
            void pressKey(const sf::Keyboard::Key& k);
            void releaseKey(const sf::Keyboard::Key& k);
            bool isPressed(const sf::Keyboard::Key& key);
            void clearInputs();

        private:    
            Keyboard();
            static Keyboard* instance;
            std::pair<bool, bool> keys[128];

    };
    
} // namespace og


#endif