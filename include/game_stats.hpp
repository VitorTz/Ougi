#ifndef CPP_GAME_GAME_STATS_HPP
#define CPP_GAME_GAME_STATS_HPP


namespace og {

    class GameStats {

        private:
            static GameStats* instance;
            double timeElapsed;
            bool gameIsRunning;
            GameStats();
        
        public:
            ~GameStats();
            static GameStats* getInstance();
            void updateTimeElapsed(double dt);
            double getTimeElapsed();
            void quitGame();
            bool isGameRunning();

    };


    extern GameStats* gameStats;

    
} // namespace og



#endif