#pragma once
#ifndef OUGI_TRANSFORM_HPP
#define OUGI_TRANSFORM_HPP
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <cstdlib>


namespace og {

    class Transform {

        public:

            Transform();
            Transform(const std::size_t zIndex);
            Transform(const sf::Vector2f& position, const std::size_t zIndex);
            Transform(const sf::Vector2f& position, const sf::Vector2f& direction, const std::size_t zIndex);
            Transform(
                const sf::Vector2f& position,
                const sf::Vector2f& direction,
                const sf::Vector2f& scale,
                const float rotation,
                const float speed,
                const std::size_t zIndex
            );
            sf::Vector2f position, direction, scale;            
            float rotation, speed;
            std::size_t zIndex;

            void normalizeVector(sf::Vector2f& v);
            const sf::Vector2f move(const double dt);
            const sf::Vector2f move(const sf::Vector2f& v);

    };
    
} // namespace og


#endif