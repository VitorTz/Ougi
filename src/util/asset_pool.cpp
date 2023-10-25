#include "../../include/util/asset_pool.hpp"



og::AssetPool* og::AssetPool::instance = nullptr;


og::AssetPool* og::AssetPool::getInstance() {
    if (!instance) {
        instance = new og::AssetPool();
    }
    return instance;
}


og::AssetPool::AssetPool() {

}


og::AssetPool::~AssetPool() {
    for (auto& pair : this->texture) {
        std::cout << "Deleting " << pair.first << " Texture\n";
        delete pair.second;
    }
    this->texture.clear();
}


void og::AssetPool::setTexture(sf::Sprite& sprite, const std::string& imagePath) {
    if (this->texture.find(imagePath) == this->texture.end()) {
        sf::Texture* t = new sf::Texture();
        t->loadFromFile(imagePath);
        this->texture.insert({imagePath, t});
    }
    sf::Texture* t = this->texture.at(imagePath);
    sprite.setTexture(*t);
}


void og::AssetPool::setTexture(sf::Sprite& sprite, const og::ImageId& imageId) {
    const std::string& imagePath = og::imagePathById.at(imageId);
    this->setTexture(sprite, imagePath);
}


