#include "../../include/scene/scene.hpp"


og::Scene::Scene(
    og::SceneId sceneId,
    std::function<void(og::SceneId)> changeScene
) : sceneId(sceneId), changeScene(changeScene) {

}


og::Scene::~Scene() {
    for (auto& pair : this->gameObjs) {        
        delete pair.second;
    }
    this->gameObjs.clear();
}


void og::Scene::addGameObj(og::GameObj* gameObj, const bool addToCamera) {
    this->gameObjs.insert({gameObj->getName(), gameObj});
    if (addToCamera) this->camera.submit(gameObj);
}


void og::Scene::rmvGameObj(const std::string& gameObjName) {
    if (this->gameObjs.find(gameObjName) != this->gameObjs.end()) {
        og::GameObj* g = this->gameObjs.at(gameObjName);
        this->camera.rmv(g);
        this->gameObjs.erase(gameObjName);
        delete g;
    }
}


og::GameObj* og::Scene::getGameObj(const std::string& gameObjName) {
    if (this->gameObjs.find(gameObjName) != this->gameObjs.end()) {
        return this->gameObjs.at(gameObjName);
    }
    return nullptr;
}


void og::Scene::update(double dt) {
    for (auto& pair : this->gameObjs) {
        pair.second->update(dt);
    }
}


void og::Scene::draw(sf::RenderWindow& window) {
    this->camera.draw(window);
}


const og::SceneId& og::Scene::getSceneId() {
    return this->sceneId;
}