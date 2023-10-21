#include "../../include/window/keyboard.hpp"


og::Keyboard* og::Keyboard::instance = nullptr;


og::Keyboard* og::Keyboard::getInstance() {
    if (!instance) {
        instance = new og::Keyboard;
    }
    return instance;
}


og::Keyboard::Keyboard() {
    
}   


og::Keyboard::~Keyboard() {

}


void og::Keyboard::clearInputs() {
    for (auto& p : this->keys)
        p.first = false;
}

void og::Keyboard::pressKey(const sf::Keyboard::Key& key) {
    std::pair<bool, bool>& p = this->keys[key];
    if (!p.second) {
        p.first = true;
        p.second = true;
    } else {
        p.first = false;
    }
}


void og::Keyboard::releaseKey(const sf::Keyboard::Key& key) {
    std::pair<bool, bool>& p = this->keys[key];
    p.first = false;
    p.second = false;
}


bool og::Keyboard::isPressed(const sf::Keyboard::Key& key) {
    return this->keys[key].first;
}
