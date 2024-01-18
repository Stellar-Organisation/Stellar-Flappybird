#pragma once

#include "ECS.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace Graphic::CMP {
class Sprite: Engine::Component {
    public:
        Sprite(std::string aPath);
        sf::Sprite _sprite;

        ~Sprite();

    private:
        sf::Texture *_texture;
};
}
