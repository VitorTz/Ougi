#ifndef OUGI_KEYBOARD_HPP
#define OUGI_KEYBOARD_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "../constants.hpp"
#include "../game_stats.hpp"


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
            std::string inputValue;

        public:

            void pressKey(const sf::Event::KeyEvent& key);
            void releaseKey(const sf::Event::KeyEvent& key);
            bool isKeyPressed(const sf::Keyboard::Key& key);
            void textEntered(const sf::Event::TextEvent& text);
            bool isSpecialLetter(const int code);
            bool isValidLetter(const int code);
            void clearKeyboardInput();
            std::string getKeyboardInput();

    }; 

    const std::map<int, std::string> specialLetterByUnicode = {
        {225, "á"},
        {224, "à"},
        {227, "ã"},
        {226, "â"},
        {233, "é"},
        {232, "è"},
        {234, "ê"},
        {237, "í"},
        {236, "ì"},
        {238, "î"},
        {243, "ó"},
        {242, "ò"},
        {245, "õ"},
        {244, "ô"},
        {250, "ú"},
        {249, "ù"},
        {251, "û"},
        {231, "ç"},
        {193, "Á"},
        {192, "À"},
        {195, "Ã"},
        {194, "Â"},
        {201, "É"},
        {200, "È"},
        {202, "Ê"},
        {205, "Í"},
        {204, "Ì"},
        {206, "Î"},
        {211, "Ó"},
        {210, "Ò"},
        {213, "Õ"},
        {212, "Ô"},
        {218, "Ú"},
        {217, "Ù"},
        {219, "Û"},
        {199, "Ç"},
    };
    
    const std::set<int> invalidCharUnicodes = {
        1,
        9,
        13,
        127,
        180,
    };
    
} // namespace og


#endif