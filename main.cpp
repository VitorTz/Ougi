#include "Window.hpp"


int main(void) {
    og::window_init();
    og::window_mainloop();
    og::window_close();
    return 0;
}