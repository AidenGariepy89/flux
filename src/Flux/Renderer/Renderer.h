#pragma once

#include "Flux/Core.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#define FLUX_SCREEN_WIDTH 1920
#define FLUX_SCREEN_HEIGHT 1080

namespace flux {
namespace renderer {

struct BoxSprite {
    sf::RectangleShape shape;
};

struct CircleSprite {
    sf::CircleShape shape;
};

void sprite_update(Ecs& ecs);
void render(Ecs& ecs, sf::RenderWindow& rw);

} // namespace renderer
} // namespace flux
