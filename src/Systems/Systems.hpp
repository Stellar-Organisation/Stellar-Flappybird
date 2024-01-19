#pragma once

#include "Core/Components/Component.hpp"
#include "ECS.hpp"
#include "../Components/CMP_Sprite.hpp"
#include "../Components/CMP_Position.hpp"

namespace Graphic::SYS {

template<Engine::ComponentConcept... Components>
class DrawSprites : public Engine::Core::System
{
    private:
        sf::RenderWindow &_window;

    public:
        explicit DrawSprites(Engine::Core::World &world, sf::RenderWindow &window)
            : Engine::Core::System(world), _window(window)
        {}

        DrawSprites(const DrawSprites &) = default;
        DrawSprites(DrawSprites &&) = default;

        DrawSprites &operator=(const DrawSprites &) = default;
        DrawSprites &operator=(DrawSprites &&) = default;

        void update() override
        {
            _world.get().template query<Components...>().forEach(
                _clock.getElapsedTime(), [this](Engine::Core::World & /*world*/, double /*deltaTime*/, std::size_t idx,
                                                Components &...components) {
                    this->updateSystem(_world.get(), _clock.getElapsedTime(), idx, components...);
                });
            _clock.restart();
        }

    private:
        void updateSystem(Engine::Core::World & /*world*/, double /*deltaTime*/, std::size_t /*idx*/, CMP::Sprite &aSprite, CMP::Position &aPos)
        {
            aSprite._sprite.setPosition(aPos.x, aPos.y);
            _window.draw(aSprite._sprite);
        }
};
}