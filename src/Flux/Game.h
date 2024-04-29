#pragma once

#include "Flux/Core.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "entt.hpp"

namespace flux {

class Scene {
public:
    Scene();

    Ecs& ecs();
private:
    Ecs m_registry{};
};

class Game {
public:
    Game();
    ~Game();

    void init();

    void run();

    void add_scene(Scene* scene);
private:
    void render_loop(Scene* scene, float dt);
private:
    sf::RenderWindow* m_window;
    std::vector<Scene*> m_scenes;
};

} // namespace flux
