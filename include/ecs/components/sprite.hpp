#ifndef OUGI_SPRITE_HPP
#define OUGI_SPRITE_HPP
#include "../ecs.hpp"


namespace og {


    class Sprite : public og::Component {

        private:
            std::string currentTexturePath;
            sf::Sprite sprite;
            sf::Vector2f dimension;

        public:

            Sprite(const std::string& name, const std::string& texturePath);
            ~Sprite();
            void changeTexture(const std::string& texturePath);
            void draw(sf::RenderWindow& window) override;
            void setGameObj(og::GameObj* gameObj) override;
            sf::Vector2f spriteSize();

    };
    
} // namespace o


#endif