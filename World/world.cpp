//
// Created by thibaultcampagne on 20/12/23.
//

#include "world.h"

World::World(std::string type, sf::VideoMode mode, sf::String &title, sf::Uint32 style,
const sf::ContextSettings &settings) {
    if (type == "2D" or type == "2d") {
        sf::RenderWindow(mode, title, style, settings);
    } else if (type == "3D" or type == "3d") {
        sf::Window(mode, title, style, settings);
    } else {
        std::cout << "Veuillez choisir un type de graphisme entre 2D et 3D" << std::endl;
    }
}

EntityManager& World::addEntityManager(std::string nameEntityManager) {
    EntityManager *comp = new EntityManager();
    std::unique_ptr<EntityManager> uptr {comp};
    entitiesManager.insert(std::make_pair(nameEntityManager, std::move(uptr)));
    if (comp->init()) {
        entityManagerMap.insert(std::make_pair(nameEntityManager, comp));
        return *comp;
    }
    return *static_cast<EntityManager*>(nullptr);
}

EntityManager& World::getEntityManager(std::string nameEntityManager) {
    auto it = entityManagerMap.find(nameEntityManager);
    if (it != entityManagerMap.end()) {
        auto ptr = entityManagerMap[nameEntityManager];
        return *static_cast<EntityManager*>(ptr);
    } else {
        this->addEntityManager(nameEntityManager);
        return this->getEntityManager(nameEntityManager);
    }
}

void World::createEntities(std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>>& mapEntityManager) {
    for (const auto& element : mapEntityManager) {
        const std::string key = element.first;
        const std::string idName = element.second.second.at(0);

        auto& entityManager = getEntityManager(key);
        for (const auto& entity : element.second.second) {
            entityManager.addEntity<Entity>(entity);
        }
    }
}