#pragma once
#ifndef OUGI_CAMERA_HPP
#define OUGI_CAMERA_HPP
#include "../ecs/ecs.hpp"


namespace og {


    class Camera {
        
        private:
            std::map<std::size_t, std::map<std::string, og::GameObj*>> camera;

        public:
            Camera();
            ~Camera();    
            void draw(sf::RenderWindow& window);
            void submit(og::GameObj* component);
            void rmv(og::GameObj* gameObj);
            bool constains(og::GameObj* component);

    };
    
} // namespace og


#endif