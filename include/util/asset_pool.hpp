#pragma once
#ifndef OUGI_ASSET_POOL_HPP
#define OUGI_ASSET_POOL_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../constants.hpp"
#include <map>


namespace og {


    class AssetPool {

        private:
            std::map<std::string, sf::Texture*> texture;

        private:
            static AssetPool* instance;
            AssetPool();
            
        public:
            static AssetPool* getInstance();
            ~AssetPool();
            void setTexture(sf::Sprite& sprite, const std::string& imagePath);
            void setTexture(sf::Sprite& sprite, const og::ImageId& imageId);
            void rmvTexture(const std::string& imagePath);
            void rmvTexture(const og::ImageId& imageId);
    };
    
} // namespace og


#endif