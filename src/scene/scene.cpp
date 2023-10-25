#include "../../include/scene/scene.hpp"


og::Scene::Scene(
    const og::SceneId& sceneId,
    std::function<void(const og::SceneId&)> changeScene
) : sceneId(sceneId), changeScene(changeScene) {

}


og::Scene::~Scene() {

}


void og::Scene::update(const double dt) {
    this->gameObjs.update(dt);    
}


void og::Scene::draw(sf::RenderWindow& window) {
    this->camera.draw(window);
}       


const og::SceneId& og::Scene::getSceneId() {
    return this->sceneId;
}