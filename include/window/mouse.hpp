#ifndef OUGI_GE_MOUSE_HPP
#define OUGI_GE_MOUSE_HPP
#include <SFML/Graphics.hpp>


namespace og {


    class Mouse {

        private:
            static Mouse* instance;
            Mouse();

        private:
            sf::Vector2i mousePos;
            std::pair<bool, bool> leftBtn, rightBtn;
            void changeMouseBtnStatus(std::pair<bool, bool>& btn, bool status);

        public:
            ~Mouse();
            static Mouse* getInstance();
            void update(sf::RenderWindow& window);
            bool isLeftBtnClicked();
            bool isRightBtnClicked();
            const sf::Vector2i& getMousePos();

    };
    
} // namespace og



#endif