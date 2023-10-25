#include "../../include/util/game_stats.hpp"


og::GameStats* og::GameStats::instance = nullptr;


og::GameStats* og::GameStats::getInstance() {
    if (!instance) {
        instance = new og::GameStats();
    }
    return instance;
}


og::GameStats::GameStats() {

}


og::GameStats::~GameStats() {
    
}


