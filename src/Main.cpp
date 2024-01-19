#include <iostream>
#include <functional>
#include <memory>
#include "ECS.hpp"
#include "Components/CMP_Position.hpp"
#include "Components/CMP_Sprite.hpp"
#include "Systems/Systems.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

int main() {
    std::cout << "Hello World!" << std::endl;

    // World setup
    Engine::Core::World world;
    world.registerComponents<Graphic::CMP::Position, Graphic::CMP::Sprite>();
    size_t backgroundId = world.createEntity();
    world.addComponentToEntity(backgroundId, Graphic::CMP::Position(0, 0));
    world.addComponentToEntity(backgroundId, Graphic::CMP::Sprite("assets/sprites/background-day.png"));

    // Window
    sf::RenderWindow window(sf::VideoMode(288, 512), "Flappy Bird");

    // Systems
    auto drawSpritesSystem = std::make_pair<std::string, std::unique_ptr<Engine::Core::System>>(
            "MySystemClass", std::make_unique<Graphic::SYS::DrawSprites<Graphic::CMP::Sprite, Graphic::CMP::Position>>(world, window));
    world.addSystem(drawSpritesSystem);

    // Main loop
    sf::Event event{};
    while (window.isOpen()) {
        window.clear();
        world.runSystems();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        window.display();
    }
    return 0;
}
