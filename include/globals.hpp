#pragma once
#ifndef OUGI_GLOBALS_HPP
#define OUGI_GLOBALS_HPP
#include "window/keyboard.hpp"
#include "window/mouse.hpp"
#include "util/game_stats.hpp"
#include "util/asset_pool.hpp"


namespace og {


    extern og::Keyboard* keyboard;
    extern og::Mouse* mouse;
    extern og::GameStats* gameStats;
    extern og::AssetPool* assetPool;

    
} // namespace og


#endif