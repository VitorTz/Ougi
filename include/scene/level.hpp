#ifndef CPP_GAME_LEVEL_HPP
#define CPP_GAME_LEVEL_HPP
#include "scene.hpp"


namespace og {


    class Level : public og::Scene {

        public:
            Level(std::function<void(og::SceneId)> func);
            
    };

    
} // namespace og


#endif