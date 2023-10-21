#ifndef OUGI_GE_CAMERA_HPP
#define OUGI_GE_CAMERA_HPP
#include <SFML/Graphics.hpp>
#include "../ecs/ecs.hpp"
#include "set"
#include <map>


namespace og {


    class Camera {

        private:
            std::map<std::size_t, std::set<og::GameObj*>> gameObjs;

        public:

            Camera();
            void submit(og::GameObj* gameObj);
            void rmv(og::GameObj* gameObj);
            void draw(sf::RenderWindow& window);

    };
    
} // namespace og



#endif