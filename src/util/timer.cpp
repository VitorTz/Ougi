#include "../../include/util/timer.hpp"


og::Timer::Timer(
    const double timeInSeconds
) : startedTime(og::gameStats->elapsedTime), timeInSeconds(timeInSeconds) {

}


void og::Timer::reset() {
    this->startedTime = og::gameStats->elapsedTime;
}


bool og::Timer::check() {
    const double elapsedTime = og::gameStats->elapsedTime;
    const bool r = (elapsedTime - this->startedTime) >= this->timeInSeconds;
    if (r) this->startedTime = elapsedTime;
    return r;
}