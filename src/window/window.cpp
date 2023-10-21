#include "../../include/window/window.hpp"


og::Window::Window()
: window(
    sf::VideoMode(og::screenWidth, og::screenHeight),
    og::screenTitle,
    sf::Style::Close | sf::Style::Titlebar
) {
    this->window.setFramerateLimit(og::screenFps);
    this->centralizeWindow();
    this->loadWindowIcon();    
    this->changeScene(og::mainScene);
}


og::Window::~Window() {
    delete og::gameStats;    
    delete this->scene;
}


void og::Window::centralizeWindow() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - og::screenWidth / 2,
            desktop.height / 2 - og::screenHeight / 2
        )
    );
}


void og::Window::loadWindowIcon() {
    sf::Image iconImage;
    if (!iconImage.loadFromFile(og::icon)) {
        std::cerr << "Game Icon not Founded!\n";
        og::gameStats->quitGame();
        return;
    }
    sf::Vector2u iconSize = iconImage.getSize();
    this->window.setIcon(iconSize.x, iconSize.y, iconImage.getPixelsPtr());
}


void og::Window::changeScene(og::SceneId sceneId) {    
    if (this->scene == nullptr || this->scene->getSceneId() != sceneId) {
        delete this->scene;
        switch (sceneId) {
            case og::SceneId::Level:
                this->scene = new og::Level([this](og::SceneId sceneId){this->changeScene(sceneId);});
                break;
            default:
                break;
        }
    }   
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
    og::gameStats->updateTimeElapsed(dt);
    og::mouse->update(this->window);
    this->scene->update(dt);
}


void og::Window::render() {
    this->window.clear(og::windowBgColor);
    this->scene->draw(this->window);
    this->window.display();
}


void og::Window::run() {
    while (this->window.isOpen() && og::gameStats->isGameRunning()) {
        this->handleInput();
        this->update();
        this->render();
        og::keyboard->clearInputs();
    }
}