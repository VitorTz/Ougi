#include "../../include/util/transform.hpp"


og::Transform::Transform(

) : scale(1.f, 1.f),
    rotation(0),
    speed(0),
    zIndex(0) {

}


og::Transform::Transform(
    const sf::Vector2f& position,
    const sf::Vector2f& direction,
    const sf::Vector2f& scale,
    const float rotation,
    const float speed,
    const std::size_t zIndex
) : position(position),
    direction(direction),
    scale(scale),
    rotation(rotation),
    speed(speed),
    zIndex(zIndex) {
    
}


og::Transform::Transform(
    const std::size_t zIndex
) : scale(1.f, 1.f),
    rotation(0),
    speed(0),
    zIndex(zIndex) {

}


og::Transform::Transform(
    const sf::Vector2f& position,
    const std::size_t zIndex
) : position(position),
    scale(1.f, 1.f),
    rotation(0),
    speed(0),
    zIndex(zIndex) {

}


og::Transform::Transform(
    const sf::Vector2f& position,
    const sf::Vector2f& direction,
    const std::size_t zIndex
) : position(position),
    direction(direction),
    scale(1.f, 1.f),
    rotation(0),
    speed(0),
    zIndex(zIndex) {

}


const sf::Vector2f og::Transform::move(const double dt) {
    this->normalizeVector(this->direction);
    const double dX = this->direction.x * dt * this->speed;
    const double dY = this->direction.y * dt * this->speed;
    this->position.x += dX;
    this->position.y += dY;
    return sf::Vector2f(dX, dY);
}


const sf::Vector2f og::Transform::move(const sf::Vector2f& v) {
    this->position.x += v.x;
    this->position.y += v.y;
    return sf::Vector2f(v.x, v.y);
}


void og::Transform::normalizeVector(sf::Vector2f& v) {
    double magnitude = std::sqrt(v.x * v.x + v.y * v.y);
    if (magnitude > 1) {
        v.x /= magnitude;
        v.y /= magnitude;
    }
}