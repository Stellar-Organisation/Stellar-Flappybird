#include <iostream>
#include "ECS.hpp"
#include "Components/Position.hpp"

int main() {
    std::cout << "Hello World!" << std::endl;
    Engine::Core::World world;
    world.registerComponent<Position>();
    size_t backgroundId = world.createEntity();
    world.addComponentToEntity(backgroundId, Position(0, 0));
    while (true) {
        world.runSystems();
    }
    return 0;
}
