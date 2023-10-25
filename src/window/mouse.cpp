#include "../../include/window/mouse.hpp"



og::Mouse* og::Mouse::instance = nullptr;


og::Mouse* og::Mouse::getInstance() {
    if (!instance) {
        instance = new og::Mouse();
    }
    return instance;
}


og::Mouse::Mouse() {

}


og::Mouse::~Mouse() {

}


void og::Mouse::updateBtnStatus(std::pair<bool, bool>& btn, bool status) {
    if (!status) {
        btn.first = btn.second = false;
        return;
    }
    if (!btn.second) {
        btn.first = true;
        btn.second = true;
        return;
    }
    btn.first = false;
}


void og::Mouse::update(sf::RenderWindow& window) {
    this->mousePos = sf::Mouse::getPosition(window);
    this->updateBtnStatus(this->leftBtn, sf::Mouse::isButtonPressed(sf::Mouse::Left));
    this->updateBtnStatus(this->rightBtn, sf::Mouse::isButtonPressed(sf::Mouse::Right));
}


const sf::Vector2i& og::Mouse::getMousePos() {
    return this->mousePos;
}


bool og::Mouse::leftBtnIsPressed() {
    return this->leftBtn.first;
}


bool og::Mouse::rightBtnIsPressed() {
    return this->rightBtn.first;
}