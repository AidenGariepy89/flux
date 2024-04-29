#include "Renderer.h"
#include "Flux/Core.h"
#include "Flux/Physics/CollisionBroad.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "entt.hpp"

namespace flux {
namespace renderer {

void box_sprite_update(Ecs& ecs) {
    auto view = ecs.view<const Transform, BoxSprite>();

    for (auto& entity : view) {
        const auto& transform = view.get<const Transform>(entity);
        auto& sprite = view.get<BoxSprite>(entity);

        sprite.shape.setPosition(transform.pos);
        sprite.shape.setRotation(transform.rot);
        sprite.shape.setScale(transform.scale);
    }
}

void circle_sprite_update(Ecs& ecs) {
    auto view = ecs.view<const Transform, CircleSprite>();

    for (auto& entity : view) {
        const auto& transform = view.get<const Transform>(entity);
        auto& sprite = view.get<CircleSprite>(entity);

        sprite.shape.setPosition(transform.pos);
        sprite.shape.setRotation(transform.rot);
        sprite.shape.setScale(transform.scale);
    }
}

void sprite_update(Ecs &ecs) {
    box_sprite_update(ecs);
    circle_sprite_update(ecs);
}

void box_render(Ecs& ecs, sf::RenderWindow& rw) {
    auto view = ecs.view<const BoxSprite>();

    for (auto& entity : view) {
        const auto& sprite = view.get<const BoxSprite>(entity);

        rw.draw(sprite.shape);
    }
}

void circle_render(Ecs& ecs, sf::RenderWindow& rw) {
    auto view = ecs.view<const CircleSprite>();

    for (auto& entity : view) {
        const auto& sprite = view.get<const CircleSprite>(entity);

        rw.draw(sprite.shape);
    }
}

void debug_render(Ecs& ecs, sf::RenderWindow& rw) {
    auto view = ecs.view<const physics::AABB>();

    for (auto& entity : view) {
        const auto& aabb = view.get<const physics::AABB>(entity);

        sf::CircleShape min(1.0f);
        sf::CircleShape max(1.0f);

        min.setFillColor(sf::Color::Cyan);
        min.setPosition(aabb.min);
        max.setFillColor(sf::Color::Cyan);
        max.setPosition(aabb.max);

        rw.draw(min);
        rw.draw(max);
    }
}

void render(Ecs& ecs, sf::RenderWindow& rw) {
    box_render(ecs, rw);
    circle_render(ecs, rw);

#if FLUX_RENDER_DEBUG
    debug_render(ecs, rw);
#endif
}

} // namespace renderer
} // namespace flux
