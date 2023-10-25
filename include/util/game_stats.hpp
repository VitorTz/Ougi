#pragma once
#ifndef OUGI_GAME_STATS_HPP
#define OUGI_GAME_STATS_HPP


namespace og {


    class GameStats {

        private:
            static GameStats* instance;
            GameStats();
        
        public:
            static GameStats* getInstance();
            ~GameStats();

        public:
            
            double elapsedTime;

    };
    
} // namespace og


#endif