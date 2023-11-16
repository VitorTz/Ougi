#ifndef OUGI_SCENE_HPP
#define OUGI_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include "../constants.hpp"
#include "../globals.hpp"
#include "../game_stats.hpp"


namespace og {


    class Scene {

        protected:
            const og::SceneId sceneId;
            const std::function<void(const og::SceneId&)> changeScene;

        public:
            Scene(
                const og::SceneId& sceneId,
                const std::function<void(const og::SceneId&)> changeScene
            );
            virtual ~Scene();
            virtual void update(const double dt);
            virtual void draw(sf::RenderWindow& window);
            const og::SceneId& getSceneId();

    };
    
} // namespace og


#endif