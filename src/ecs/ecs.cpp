#include "../../include/ecs/ecs.hpp"



og::GameObj::GameObj(
    const std::string& name
) : name(name) {

}


og::GameObj::GameObj(
    const std::string& name,
    og::Transform transform
) : name(name), transform(transform) {

}


og::GameObj::~GameObj() {
    std::cout << "Deleting " << this->name << " GameObj\n";
    for (auto& pair : this->components) {
        delete pair.second;
    }
    this->components.clear();
}


void og::GameObj::update(double dt) {
    for (auto& pair : this->components) {
        pair.second->update(dt);
    }
}


void og::GameObj::draw(sf::RenderWindow& window) {
    for (auto& pair : this->components) {
        pair.second->draw(window);
    }
}


void og::GameObj::addComponent(og::Component* component) {
    if (this->components.find(component->getName()) == this->components.end()) {
        this->components.insert({component->getName(), component});
        component->setGameObj(this);
    }
}


void og::GameObj::rmvComponent(const std::string& componentName) {
    if (this->components.find(componentName) != this->components.end()) {
        og::Component* c = this->components.at(componentName);
        this->components.erase(componentName);
        delete c;
    }
}


og::Component* og::GameObj::getComponent(const std::string& componentName) {
    if (this->components.find(componentName) != this->components.end()) {
        return this->components.at(componentName);
    }
    return nullptr;
}


const std::string& og::GameObj::getName() {
    return this->name;
}



og::Component::Component(const std::string& name) : name(name) {

}


og::Component::~Component() {
    std::cout << "Deleting " << this->name << " Component\n";
}


void og::Component::update(double dt) {
    
}   


void og::Component::draw(sf::RenderWindow& window) {
    
}


void og::Component::setGameObj(og::GameObj* gameObj) {
    this->gameObj = gameObj;
}


const std::string& og::Component::getName() {
    return this->name;
}