//
// Created by thibaultcampagne on 20/12/23.
//

#include "world.h"

World::World(std::string type, sf::VideoMode mode, const std::string &title, sf::Uint32 style,
const sf::ContextSettings &settings) {
    if (type == "2D" or type == "2d") {
        sf::RenderWindow(mode, title, style, settings);
    } else if (type == "3D" or type == "3d") {
        sf::Window(mode, title, style, settings);
    } else {
        std::cout << "Veuillez choisir un type de graphisme entre 2D et 3D" << std::endl;
    }
}

void World::createEntities(std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager) {
    for (const auto& element : mapEntityManager) {
        const std::string key = element.first;
        std::unique_ptr<EntityManager> entityManager = std::move(element.second.first);

        std::cout << key << std::endl;
        std::cout << entityManager.get() << std::endl;
        std::cout << entityManager.get() << std::endl;

    }
}