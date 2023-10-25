#pragma once
#ifndef OUGI_SCENE_HPP
#define OUGI_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <functional>
#include "../constants.hpp"
#include "../ecs/components/components.hpp"
#include "../window/camera.hpp"


namespace og {


    class Scene {

        private:
            og::SceneId sceneId;
        
        protected:
            std::function<void(const og::SceneId&)> changeScene;
            og::Camera camera;
            og::Group gameObjs;

        public:
            Scene(const og::SceneId& sceneId, std::function<void(const og::SceneId&)> changeScene);
            virtual ~Scene();
            virtual void update(const double dt);
            virtual void draw(sf::RenderWindow& window);            
            const og::SceneId& getSceneId();

    };
    
} // namespace og



#endif