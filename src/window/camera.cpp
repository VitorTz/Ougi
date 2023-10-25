#include "../../include/window/camera.hpp"



og::Camera::Camera() {

}


og::Camera::~Camera() {

}


void og::Camera::submit(og::GameObj* gameObj) {
    const std::size_t zIndex = gameObj->transform.zIndex;
    if (this->camera.find(zIndex) == this->camera.end()) {
        this->camera.insert({zIndex, {}});
    }
    this->camera.at(zIndex).insert({gameObj->getName(), gameObj});
}


void og::Camera::draw(sf::RenderWindow& window) {
    for (auto& pair : this->camera)
        for (auto& objs : pair.second)
            objs.second->draw(window);
}



void og::Camera::rmv(og::GameObj* gameObj) {
    const std::size_t zIndex = gameObj->transform.zIndex;
    if (this->camera.find(zIndex) != this->camera.end()) {
        this->camera.at(zIndex).erase(gameObj->getName());
    }
}


bool og::Camera::constains(og::GameObj* gameObj) {
    const std::size_t zIndex = gameObj->transform.zIndex;
    if (this->camera.find(zIndex) != this->camera.end()) {
        std::map<std::string, og::GameObj*>& m = this->camera.at(zIndex);
        return m.find(gameObj->getName()) != m.end();
    }
    return false;
}
