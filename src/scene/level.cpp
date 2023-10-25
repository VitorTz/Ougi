#include "../../include/scene/level.hpp"


og::Level::Level(
    std::function<void(const og::SceneId&)> changeScene
) : og::Scene(og::SceneId::Level, changeScene) {
    og::GameObj* player = new og::GameObj("Player");
    player->group.add(new og::Sprite("PlayerImage", og::ImageId::Icon), player);
    this->gameObjs.add(player);
    this->camera.submit(player);
}