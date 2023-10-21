#ifndef CPP_GAME_SCENE_HPP
#define CPP_GAME_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include <map>
#include "../constants.hpp"
#include "../globals.hpp"
#include "../game_stats.hpp"
#include "../ecs/components.hpp"
#include "../util/camera.hpp"


namespace og {

    class Scene {
        
        protected:

            og::SceneId sceneId;
            std::function<void(og::SceneId)> changeScene;
            std::map<std::string, og::GameObj*> gameObjs;
            og::Camera camera;

        protected:
        
            void addGameObj(og::GameObj* gameObj, const bool addToCamera);
            og::GameObj* getGameObj(const std::string& gameObjName); 
            void rmvGameObj(const std::string& gameObjName);

        public:

            Scene(og::SceneId sceneId, std::function<void(og::SceneId)> changeScene);
            virtual ~Scene();
            virtual void update(double dt);
            virtual void draw(sf::RenderWindow& window);
            const og::SceneId& getSceneId();

    };
    
} // namespace og


#endif