#pragma once

#include "ECS.hpp"
#include "../Components/CMP_Sprite.hpp"
#include "../Components/CMP_Position.hpp"
#include "../Handlers/HND_Window.hpp"

namespace Graphic::SYS {

    std::function<void (Engine::Core::World &, double, std::size_t, CMP::Sprite &, CMP::Position &)> drawSprites = [](Engine::Core::World & /*world*/, double /*deltaTime*/, std::size_t /*idx*/, CMP::Sprite &aSprite, CMP::Position &aPos) {
        aSprite._sprite.setPosition(aPos.x, aPos.y);
        HND::Window &windowHandler = HND::Window::getInstance();
        windowHandler._window.draw(aSprite._sprite);
    };
}