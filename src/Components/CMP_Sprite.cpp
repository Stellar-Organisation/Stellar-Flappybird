#include "CMP_Sprite.hpp"
#include <iostream>

namespace Graphic::CMP {
    Sprite::Sprite(std::string aPath) {
        _texture = new sf::Texture();
        _texture->loadFromFile(aPath);
        _sprite.setTexture(*_texture);
    }

    Sprite::~Sprite() {
        // NOTE: for now Sprite gets deleted at beginning :/
        //delete _texture;
    }
}
