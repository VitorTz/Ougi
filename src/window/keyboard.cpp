#include "../../include/window/keyboard.hpp"
#include <iostream>



og::Keyboard* og::Keyboard::instance = nullptr;


og::Keyboard* og::Keyboard::getInstance() {
    if (!instance) {
        instance = new og::Keyboard();
    }
    return instance;
}


og::Keyboard::Keyboard() {
    
}


og::Keyboard::~Keyboard() {

}



void og::Keyboard::pressKey(const sf::Event::KeyEvent& key) {
    if (key.code >= 0) {
        this->keys[key.code] = false;
    }
}


void og::Keyboard::releaseKey(const sf::Event::KeyEvent& key) {
    if (key.code >= 0) {
        this->keys[key.code] = true;
    }
}


bool og::Keyboard::isKeyPressed(const sf::Keyboard::Key& key) {
    return this->keys[(int)key];
}


bool og::Keyboard::isSpecialLetter(const int code) {
    return (og::specialLetterByUnicode.find(code) != og::specialLetterByUnicode.end());
}

bool og::Keyboard::isValidLetter(const int code) {
    return (og::invalidCharUnicodes.find(code) == og::invalidCharUnicodes.end());
}


void og::Keyboard::textEntered(const sf::Event::TextEvent& text) {    
    const int unicode = text.unicode;    
    if (unicode == '\b' && !this->inputValue.empty()) {
        this->inputValue.pop_back();
        return;
    }
    if (!this->isValidLetter(unicode) || (this->inputValue.size() >= og::KEYBOARD_STRING_VALUE_MAX_LENGTH)) {
        return;
    } 
    if (this->isSpecialLetter(unicode)) {
        this->inputValue += og::specialLetterByUnicode.at(unicode);
        return;
    }
    this->inputValue += (char) unicode;
    
}


void og::Keyboard::clearKeyboardInput() {
    this->inputValue.clear();
}


std::string og::Keyboard::getKeyboardInput() {
    return this->inputValue;
}