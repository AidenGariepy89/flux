#include "Flux/Core.h"
#include "Flux/Game.h"
#include "Flux/Physics/CollisionBroad.h"
#include "Flux/Physics/Physics.h"
#include "Flux/Renderer/Renderer.h"
#include "SFML/Graphics/RectangleShape.hpp"

struct Player;

using namespace flux;

Scene* setup() {
    Scene* scene = new Scene();
    Ecs& ecs = scene->ecs();

    Vec2 size(50, 50);
    sf::RectangleShape rect;
    rect.setSize(size);
    rect.setOrigin(size.x / 2.0f, size.y / 2.0f);
    rect.setFillColor(sf::Color::Red);

    auto entity1 = ecs.create();
    ecs.emplace<Transform>(
        entity1,
        Vec2(100, 400),
        0.0f,
        Vec2(1, 1)
    );
    ecs.emplace<renderer::BoxSprite>(entity1, rect);
    ecs.emplace<physics::Box>(entity1, size.x, size.y, 1.0f);
    ecs.emplace<physics::RigidBody>(entity1, physics::rb_with(
        Vec2(100.0f, 0.0f),
        Vec2(),
        50.0f,
        0.0f
    ));
    ecs.emplace<physics::AABB>(entity1, physics::AABB{});

    auto entity2 = ecs.create();
    rect.setFillColor(sf::Color::Blue);
    ecs.emplace<Transform>(
        entity2, 
        Vec2(1200, 400),
        0.0f,
        Vec2(1, 1)
    );
    ecs.emplace<renderer::BoxSprite>(entity2, rect);
    ecs.emplace<physics::Box>(entity2, size.x, size.y, 1.0f);
    ecs.emplace<physics::RigidBody>(entity2, physics::rb_with(
        Vec2(-100.0f, 0.0f),
        Vec2(),
        -50.0f,
        0.0f
    ));
    ecs.emplace<physics::AABB>(entity2, physics::AABB{});

    return scene;
}

int main() {
    Game game;

    Scene* scene = setup();

    game.add_scene(scene);
    game.run();
}
