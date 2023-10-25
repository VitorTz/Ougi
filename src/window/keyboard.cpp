#include "../../include/window/keyboard.hpp"


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


void og::Keyboard::update() {
    for (int i = 0; i < 256; i++) {
        this->keys[i] = false;
    }
}


void og::Keyboard::pressKey(const sf::Keyboard::Key& k) {
    if (this->keysLock[k] == true) {
        this->keys[k] = false;
        return;
    }    
    this->keys[k] = true;
    this->keys[k] = true;

}


void og::Keyboard::releaseKey(const sf::Keyboard::Key& k) {
    this->keys[k] = false;
    this->keysLock[k] = false;
}


bool og::Keyboard::isPressed(const sf::Keyboard::Key& k) {
    return this->keys[k];
}