#pragma once
#ifndef OUGI_SPRITE_COMPONENT_HPP
#define OUGI_SPRITE_COMPONENT_HPP
#include "../ecs.hpp"


namespace og {


    class Sprite : public og::Component {


        private:
            sf::Sprite sprite;
            std::string imageKey;

        public:
            Sprite(const std::string& name, const std::string& imagePath);
            Sprite(const std::string& name, const og::ImageId& imageId);
            ~Sprite();
            void setTexture(const std::string& imagePath);
            void setTexture(const og::ImageId& imageId);
            void draw(sf::RenderWindow& window) override;

    };
    
} // namespace og


#endif