#include "../../include/window/window.hpp"


og::Window* og::Window::instance = nullptr;


og::Window* og::Window::getInstance() {
    if (!instance) 
        instance = new og::Window();
    return instance;
}


og::Window::Window(

) : window(
    sf::VideoMode(og::SCREEN_WIDTH, og::SCREEN_HEIGHT),
    og::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    this->window.setFramerateLimit(og::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - og::SCREEN_WIDTH / 2,
            desktop.height / 2 - og::SCREEN_HEIGHT / 2
        )
    );
    
    this->initScreenIcon();

}


og::Window::~Window() {
    delete og::mouse;
}


void og::Window::initScreenIcon() {
    sf::Image icon;
    if (!icon.loadFromFile(og::SCREEN_ICON)) {
        this->window.close();
        std::cerr << "Image icon not founded!\n";
        return;
    }
    sf::Vector2u iconSize = icon.getSize();
    this->window.setIcon( 
        iconSize.x, iconSize.y, icon.getPixelsPtr()
    );

}


void og::Window::handleInput() {
    sf::Event e;
    while (this->window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                this->window.close();
                break;
            default:
                break;
        }
    }
}


void og::Window::update() {
    const double dt = this->clock.restart().asSeconds();
    og::mouse->update(this->window);    
}


void og::Window::draw() {
    this->window.clear(og::SCREEN_COLOR);
    this->window.display();
}


void og::Window::run() {
    while (this->window.isOpen()) {
        this->handleInput();
        this->update();
        this->draw();
    }
}
