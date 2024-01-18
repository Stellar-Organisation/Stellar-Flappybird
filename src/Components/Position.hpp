#include "ECS.hpp"

class Position: Engine::Component {
    public:
        Position(int x, int y): x(x), y(y) {}
        int x;
        int y;
};
