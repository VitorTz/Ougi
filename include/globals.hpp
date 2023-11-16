#ifndef OUGI_GLOBALS_HPP
#define OUGI_GLOBALS_HPP
#include "window/mouse.hpp"
#include "window/keyboard.hpp"


namespace og {

    extern og::Mouse* mouse;
    extern og::Keyboard* keyboard;
    
    void initGlobals();    
    void deleteGlobals();

    
} // namespace og



#endif