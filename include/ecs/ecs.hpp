#ifndef OUGI_GE_ECS_HPP
#define OUGI_GE_ECS_HPP
#include <map>
#include <iostream>
#include "../constants.hpp"
#include "../globals.hpp"
#include "../game_stats.hpp"
#include "../util/transform.hpp"


namespace og {

    class Component;

    class GameObj {

        private:
            std::map<std::string, og::Component*> components;
            const std::string name;
        
        public:
            og::Transform transform;

        public:

            GameObj(const std::string& name);
            GameObj(const std::string& name, og::Transform transform);
            ~GameObj();
            void update(double dt);
            void draw(sf::RenderWindow& window);
            void addComponent(og::Component* component);
            void rmvComponent(const std::string& componentName);
            og::Component* getComponent(const std::string& componentName);
            const std::string& getName();

    };


    class Component {

        protected:
            const std::string name;
            og::GameObj* gameObj;

        public:
            Component(const std::string& name);
            virtual ~Component();
            virtual void update(double dt);
            virtual void draw(sf::RenderWindow& window);
            virtual void setGameObj(og::GameObj* gameObj);
            const std::string& getName();

    };  
    
} // namespace og


#endif