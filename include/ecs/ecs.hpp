#pragma once
#ifndef OUGI_ECS_HPP
#define OUGI_ECS_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../util/transform.hpp"
#include "../util/asset_pool.hpp"
#include "../util/timer.hpp"
#include "../globals.hpp"
#include <map>
#include <string>


namespace og {

    class Component;
    class GameObj;

    class Group {

        private:
            std::map<std::string, og::Component*> components;

        public:
            Group();
            ~Group();
            void add(og::Component* component);
            void add(og::Component* component, og::GameObj* gameObj);
            bool rmv(const std::string& componentName);
            bool constains(const std::string& componentName);
            og::Component* get(const std::string& componentName);
            void update(const double dt);
            void draw(sf::RenderWindow& window);

    };


    class Component {

        private:
            const std::string name;
        
        protected:
            og::GameObj* gameObj;

        public:
            Component(const std::string& name);
            virtual ~Component();
            virtual void update(const double dt);
            virtual void draw(sf::RenderWindow& window);
            virtual void setGameObj(og::GameObj* gameObj);
            const std::string& getName();
            og::Group group;
        
    };


    class GameObj : public og::Component {

        public:

            GameObj(const std::string& name);
            GameObj(const std::string& name, const og::Transform transform);
            ~GameObj();
            void update(const double dt) override;
            og::Transform transform;
        

    };
    
} // namespace og


#endif