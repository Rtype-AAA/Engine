//
// Created by thibaultcampagne on 28/12/23.
//

#include "gameEngine.h"

GameEngine::GameEngine(sf::VideoMode mode, std::string type, sf::String title, sf::Uint32 style,
                       const sf::ContextSettings &settings) {
    if (type == "2D" or type == "2d") {
        window = std::make_unique<sf::RenderWindow>(mode, title, style, settings);
    } else if (type == "3D" or type == "3d") {
        std::cout << "Veuillez choisir la 2D, la 3D n'est pas encore fonctionnel" << std::endl;
    } else {
        std::cout << "Veuillez choisir un type de graphisme entre 2D et 3D" << std::endl;
        exit(0);
    }
}

void GameEngine::setWindow() {
    return;
}

void GameEngine::initialize(std::string pathRessources) {
    return;
}

bool GameEngine::isWindowOpen() {
    return std::visit([](const auto& w) -> bool {
        return w->isOpen();
    }, window);
}

void GameEngine::updateGameEngine() {
    return;
}

void GameEngine::renderGameEngine() {
    std::visit([](auto& w) {
        if constexpr (std::is_same_v<std::decay_t<decltype(*w)>, sf::RenderWindow>) {
            w->clear();
            w->display();
        }
    }, window);
}

void GameEngine::run(std::map<std::string, std::unique_ptr<World>> mapWorld, std::string pathRessources) {
    for (const auto &element: mapWorld) {
        std::cout << element.first << std::endl;
    }
    initialize(pathRessources);

    while (isWindowOpen()) {
        updateGameEngine();
        renderGameEngine();
    }
}

void GameEngine::initializeTexture() {
    return;
}