#include "../../include/util/transform.hpp"


og::Transform::Transform() 
: rotation(0.f), scale(1.f), zIndex(0) {

}


og::Transform::Transform(std::size_t zIndex) 
: rotation(0.f), scale(1.f), zIndex(zIndex) {

}


og::Transform::Transform(
    const sf::Vector2f& position,
    const sf::Vector2f& direction,
    float speed,
    float rotation,
    float scale,
    std::size_t zIndex
) : position(position),
    direction(direction),
    speed(speed),
    rotation(rotation),
    scale(scale),
    zIndex(zIndex) {

}


og::Transform::Transform(const sf::Vector2f& position, float speed, std::size_t zIndex)
:   position(position),
    speed(speed),
    scale(1.f),
    zIndex(zIndex) {

}


sf::Vector2f og::Transform::move(double dt) {
    float deltaX = this->direction.x * dt * this->speed;
    float deltaY = this->direction.y * dt * this->speed;
    this->position.x += deltaX;
    this->position.y += deltaY;
    return {deltaX, deltaY};
}


sf::Vector2f og::Transform::move(const sf::Vector2f& v) {
    this->position.x += v.x;
    this->position.y += v.y;
    return {v.x, v.y};
}

