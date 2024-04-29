#include <iostream>

#include "Game.h"
#include "Flux/Physics/Physics.h"
#include "Flux/Renderer/Renderer.h"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "entt.hpp"

namespace flux {

Game::Game() {
    m_window = new sf::RenderWindow(sf::VideoMode(FLUX_SCREEN_WIDTH, FLUX_SCREEN_HEIGHT), "game");
}

Game::~Game() {
    delete m_window;

    for (Scene* scene : m_scenes) {
        delete scene;
    }
}

void Game::init() {
}

void Game::run() {
    if (m_scenes.empty()) {
        std::cout << "No scenes in Game!\n";
        return;
    }

    Scene* active_scene = m_scenes[0];
    sf::Clock clock;
    float dt = 0;

    while (m_window->isOpen()) {
        this->render_loop(active_scene, dt);
        dt = clock.restart().asSeconds();
    }
}

void Game::render_loop(Scene* scene, float dt) {
    sf::Event event;

    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window->close();
        }
    }

    m_window->clear(sf::Color::Black);

    physics::update(scene->ecs(), dt);

    renderer::sprite_update(scene->ecs());
    renderer::render(scene->ecs(), *m_window);

    m_window->display();
}

void Game::add_scene(Scene* scene) {
    m_scenes.push_back(scene);
}

Scene::Scene() {
}

Ecs& Scene::ecs() {
    return m_registry;
}

} // namespace flux
