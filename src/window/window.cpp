#include "../../include/window/window.hpp"



og::Window* og::Window::instance = nullptr;


og::Window* og::Window::getInstance() {
    if (!instance) {
        instance = new og::Window();
    }
    return instance;
}


og::Window::Window()
: window(
    sf::VideoMode(og::SCREEN_WIDTH, og::SCREEN_HEIGHT),
    og::SCREEN_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    this->window.setFramerateLimit(og::fps);
    sf::Image icon;
    icon.loadFromFile(og::imagePathById.at(og::ImageId::Icon));
    sf::Vector2u iconSize = icon.getSize();
    this->window.setIcon(iconSize.x, iconSize.y, icon.getPixelsPtr());
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - og::SCREEN_WIDTH / 2,
            desktop.height / 2 - og::SCREEN_HEIGHT / 2
        )
    );

    this->changeScene = [this](const og::SceneId& sceneId) {
        if (this->scene->getSceneId() != sceneId) {
            delete this->scene;
            switch (sceneId) {
                case og::SceneId::Level:
                    this->scene = new og::Level(this->changeScene);
                    break;
                default:
                    break;
            }
        }
    };

    this->scene = new og::Level(this->changeScene);

}


og::Window::~Window() {
    delete this->scene;
    delete og::keyboard;
    delete og::gameStats;
    delete og::mouse;
    delete og::assetPool;
}


void og::Window::handleInput() {
    sf::Event e;
    while (this->window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                this->window.close();
                break;
            case sf::Event::KeyPressed:
                og::keyboard->pressKey(e.key.code);
                break;
            case sf::Event::KeyReleased:
                og::keyboard->releaseKey(e.key.code);
                break;                
            default:
                break;
        }
    }
}


void og::Window::update() {
    const double dt = this->clock.restart().asSeconds();
    og::gameStats->elapsedTime += dt;
    og::mouse->update(this->window);
    this->scene->update(dt);
    og::keyboard->update();    
}


void og::Window::draw() {
    this->window.clear();
    this->scene->draw(this->window);
    this->window.display();
}


void og::Window::run() {
    while (this->window.isOpen()) {
        this->handleInput();
        this->update();
        this->draw();
    }
}