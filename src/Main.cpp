#include <iostream>
#include <functional>
#include "ECS.hpp"
#include "Components/CMP_Position.hpp"
#include "Components/CMP_Sprite.hpp"
#include "Handlers/HND_Window.hpp"
#include "Systems/Systems.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

int main() {
    std::cout << "Hello World!" << std::endl;

    // World setup
    Engine::Core::World world;
    world.registerComponent<Graphic::CMP::Position>();
    world.registerComponent<Graphic::CMP::Sprite>();
    size_t backgroundId = world.createEntity();
    world.addComponentToEntity(backgroundId, Graphic::CMP::Position(0, 0));
    world.addComponentToEntity(backgroundId, Graphic::CMP::Sprite("assets/sprites/background-day.png"));

    // Window
    Graphic::HND::Window &windowHandler = Graphic::HND::Window::getInstance();
    windowHandler._window.create(sf::VideoMode(288, 512), "Flappy Bird");

    // Systems
    auto drawSpritesSystem = Engine::Core::createSystem<Graphic::CMP::Sprite, Graphic::CMP::Position>(
    world, "Display sprites", Graphic::SYS::drawSprites);
    world.addSystem(drawSpritesSystem);

    // Main loop
    sf::Event event{};
    while (windowHandler._window.isOpen()) {
        windowHandler._window.clear();
        world.runSystems();
        while (windowHandler._window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
                windowHandler._window.close();
            }
        }
        windowHandler._window.display();
    }
    return 0;
}
