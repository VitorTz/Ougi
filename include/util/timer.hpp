#pragma once
#ifndef OUGI_TIMER_HPP
#define OUGI_TIMER_HPP
#include "../globals.hpp"


namespace og {


    class Timer {

        private:
            double startedTime;
            const double timeInSeconds;

        public:
            Timer(const double timeInSeconds);
            void reset();
            bool check();

    };
    
} // namespace og


#endif