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


void og::Mouse::changeMouseBtnStatus(std::pair<bool, bool>& m, bool status) {
    if (!status) {
        m.first = m.second = false;
        return;
    } 
    m.first = !m.second;
    if (!m.second) m.second = true;
}


void og::Mouse::update(sf::RenderWindow& window) {
    this->mousePos = sf::Mouse::getPosition(window);
    this->changeMouseBtnStatus(this->leftBtn, sf::Mouse::isButtonPressed(sf::Mouse::Left));
    this->changeMouseBtnStatus(this->rightBtn, sf::Mouse::isButtonPressed(sf::Mouse::Right));
}


bool og::Mouse::isLeftBtnClicked() {
    return this->leftBtn.first;
}


bool og::Mouse::isRightBtnClicked() {
    return this->rightBtn.first;
}


const sf::Vector2i& og::Mouse::getMousePos() {
    return this->mousePos;
}