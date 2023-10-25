#pragma once
#ifndef OUGI_CONSTANTS_HPP
#define OUGI_CONSTANTS_HPP
#include <string>


namespace og {


    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const std::string SCREEN_TITLE = "Ougi!";
    const int fps = 60;
    const std::string SCREEN_ICON = "res/icon/Ougi.png";

    // enum
    enum class SceneId {
        Level
    };

    enum class ImageId {
        Icon
    };

    const std::map<og::ImageId, std::string> imagePathById = {
        {og::ImageId::Icon, "res/icon/Ougi.png"}
    };
    
} // namespace og



#endif