#include "../include/globals.hpp"


og::Mouse* og::mouse = nullptr;


og::Keyboard* og::keyboard = nullptr;


void og::initGlobals() {
    og::mouse = og::Mouse::getInstance();
    og::keyboard = og::Keyboard::getInstance();
}


void og::deleteGlobals() {
    delete og::mouse;
    delete og::keyboard;
}