#ifndef OUGI_GE_TRANSFORM_HPP
#define OUGI_GE_TRANSFORM_HPP
#include <SFML/System/Vector2.hpp>
#include <cstdlib>


namespace og {

    class Transform {

        public:

            Transform();
            Transform(std::size_t zIndex);
            Transform(const sf::Vector2f& position, const sf::Vector2f& direction, float speed, float rotation, float scale, std::size_t zIndex);
            Transform(const sf::Vector2f& position, float speed, std::size_t zIndex);
            sf::Vector2f position;
            sf::Vector2f direction;
            float speed;
            float rotation;
            float scale;
            std::size_t zIndex;

            sf::Vector2f move(double dt);
            sf::Vector2f move(const sf::Vector2f& v);

    }; 
    
} // namespace og


#endif