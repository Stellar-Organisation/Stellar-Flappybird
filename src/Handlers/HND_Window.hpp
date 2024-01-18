#pragma once

#include <SFML/Graphics.hpp>

namespace Graphic::HND {
    class Window {
        public:
            Window();

            static Window &getInstance()
            {
                static Window instance;
                return instance;
            }

            sf::RenderWindow _window;
    }; 
}