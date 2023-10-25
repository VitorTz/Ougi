#include "../../../include/ecs/components/sprite.hpp"



og::Sprite::Sprite(
    const std::string& name, 
    const std::string& imagePath
) : og::Component(name) {
    this->setTexture(imagePath);
}


og::Sprite::Sprite(
    const std::string& name, 
    const og::ImageId& imageId
) : og::Component(name) {
    this->setTexture(imageId);
}   


og::Sprite::~Sprite() {
    
}


void og::Sprite::draw(sf::RenderWindow& window) {
    og::Transform& t = this->gameObj->transform;
    this->sprite.setPosition(t.position);
    this->sprite.setScale(t.scale);
    this->sprite.setRotation(t.rotation);
    window.draw(this->sprite);
}


void og::Sprite::setTexture(const std::string& imagePath) {
    this->imageKey = imagePath;
    og::assetPool->setTexture(this->sprite, this->imageKey);
}


void og::Sprite::setTexture(const og::ImageId& imageId) {
    this->imageKey = og::imagePathById.at(imageId);
    og::assetPool->setTexture(this->sprite, this->imageKey);
}