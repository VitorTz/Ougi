#include "../../include/util/camera.hpp"


og::Camera::Camera() {

}


void og::Camera::submit(og::GameObj* gameObj) {
    const std::size_t zIndex = gameObj->transform.zIndex;
    if (this->gameObjs.find(zIndex) == this->gameObjs.end()) {
        this->gameObjs.insert({zIndex, {}});
    }
    this->gameObjs.at(zIndex).insert(gameObj);
}


void og::Camera::rmv(og::GameObj* gameObj) {
    const std::size_t zIndex = gameObj->transform.zIndex;
    if (this->gameObjs.find(zIndex) != this->gameObjs.end()) {
        this->gameObjs.at(zIndex).erase(gameObj);
    }
}


void og::Camera::draw(sf::RenderWindow& window) {
    for (auto& s : this->gameObjs) {
        for (og::GameObj* g : s.second) {
            g->draw(window);
        }
    }
}