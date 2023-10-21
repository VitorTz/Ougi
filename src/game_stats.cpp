#include "../include/game_stats.hpp"

og::GameStats* og::GameStats::instance = nullptr;


og::GameStats* og::GameStats::getInstance() {
    if (!instance) {
        instance = new og::GameStats();
    }
    return instance;
}


og::GameStats::GameStats() : timeElapsed(0.0), gameIsRunning(true) {

}


og::GameStats::~GameStats() {

}



void og::GameStats::updateTimeElapsed(double dt) {
    this->timeElapsed += dt;
}


double og::GameStats::getTimeElapsed() {
    return this->timeElapsed;
}


void og::GameStats::quitGame() {
    this->gameIsRunning = false;
}


bool og::GameStats::isGameRunning() {
    return this->gameIsRunning;
}