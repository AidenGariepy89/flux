#pragma once

#include "SFML/Graphics/RectangleShape.hpp"
#include "entt.hpp"

namespace flux {

#define FLUX_RENDER_DEBUG true

typedef entt::registry Ecs;
typedef sf::Vector2f Vec2;

struct Transform {
    Vec2 pos;
    float rot;
    Vec2 scale;
};

} // namespace flux
