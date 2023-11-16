#include "../../include/util/transform.hpp"



og::Transform::Transform(

) : og::Transform(0) {

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
    const sf::Vector2f& direction,
    const double speed,
    const std::size_t zIndex
) : position(position),
    direction(direction),
    scale(1.f, 1.f), 
    rotation(0), 
    speed(speed), 
    zIndex(zIndex) {

}


og::Transform::Transform(
    const sf::Vector2f& position,
    const sf::Vector2f& dimension,
    const sf::Vector2f& direction,
    const sf::Vector2f& scale,
    const double rotation,
    const double speed,
    const std::size_t zIndex
) : position(position),
    dimension(dimension),
    direction(direction),
    scale(scale), 
    rotation(rotation), 
    speed(speed), 
    zIndex(zIndex) {

}



sf::Vector2f og::Transform::move(const double dt) {
    const double dx = this->speed * this->direction.x * dt;
    const double dy = this->speed * this->dimension.y * dt;
    this->position.x += dx;
    this->position.y += dy;
    return sf::Vector2f(dx, dy);
}


sf::Vector2f og::Transform::move(const sf::Vector2f& pos) {
    this->position.x += pos.x;
    this->position.y += pos.y;
    return sf::Vector2f(pos.x, pos.y);
}