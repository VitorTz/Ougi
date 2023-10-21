#include "../../include/scene/level.hpp"


og::Level::Level(std::function<void(og::SceneId)> func) 
: og::Scene(og::SceneId::Level, func) {
    this->addGameObj(new og::GameObj("Player"), true);
}

