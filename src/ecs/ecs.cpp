#include "../../include/ecs/ecs.hpp"


og::Component::Component(
    const std::string& name
) : name(name), gameObj(nullptr) {

}


og::Component::~Component() {
    
}


void og::Component::update(const double dt) {
    this->group.update(dt);
}


void og::Component::draw(sf::RenderWindow& window) {
    this->group.draw(window);
}


void og::Component::setGameObj(og::GameObj* gameObj) {
    this->gameObj = gameObj;
}


const std::string& og::Component::getName() {
    return this->name;
}



og::Group::Group() {

}


og::Group::~Group() {
    for (auto& pair : this->components) {
        std::cout << "Deleting " << pair.first << '\n';
        delete pair.second;
    }
    this->components.clear();
}


void og::Group::add(og::Component* component) {
    this->components.insert({component->getName(), component});   
}


void og::Group::add(og::Component* component, og::GameObj* gameObj) {
    this->components.insert({component->getName(), component});   
    component->setGameObj(gameObj);
}


og::Component* og::Group::get(const std::string& componentName) {
    return this->components.at(componentName);
}


bool og::Group::rmv(const std::string& componentName) {
    if (this->components.find(componentName) != this->components.end()) {
        og::Component* c = this->components.at(componentName);
        this->components.erase(componentName);
        delete c;
        return true;
    }
    return false;
}


bool og::Group::constains(const std::string& componentName) {
    return this->components.find(componentName) != this->components.end();
}


void og::Group::update(const double dt) {
    for (auto& pair : this->components) {
        pair.second->update(dt);
    }
}


void og::Group::draw(sf::RenderWindow& window) {
    for (auto& pair : this->components) {
        pair.second->draw(window);
    }
}




og::GameObj::GameObj(
    const std::string& name
) : og::Component(name) {

}


og::GameObj::GameObj(
    const std::string& name,
    const og::Transform transform
) : og::Component(name), transform(transform) {

}


og::GameObj::~GameObj() {
    
}


void og::GameObj::update(const double dt) {
    og::Component::update(dt);
    this->transform.move(dt);
}