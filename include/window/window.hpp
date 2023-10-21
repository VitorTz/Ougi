#ifndef CPP_GAME_WINDOW_HPP
#define CPP_GAME_WINDOW_HPP
#include "../scene/scenes.hpp"


namespace og {

    class Window {

        private:

            sf::RenderWindow window;
            sf::Clock clock;
            og::Scene* scene;
            void changeScene(og::SceneId sceneId);
            void centralizeWindow();
            void loadWindowIcon();
            void handleInput();
            void update();
            void render();

        public:
        
            Window();
            ~Window();
            void run();

    };  
    
} // namespace og


#endif