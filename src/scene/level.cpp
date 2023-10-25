#include "../../include/scene/level.hpp"


og::Level::Level(
    std::function<void(const og::SceneId&)> changeScene
) : og::Scene(og::SceneId::Level, changeScene) {
    
}