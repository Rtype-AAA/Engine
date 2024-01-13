//
// Created by thibaultcampagne on 20/12/23.
//

#include "world.h"

#include <utility>

bool World::init() {
    return true;
}

void World::createEntities(std::map<std::string, std::pair<std::unique_ptr<EntityManager>,
                           std::vector<std::string>>>& mapEntityManager) {
    for (const auto& element : mapEntityManager) {
        const std::string key = element.first;
        auto &entityManager = getEntityManager(key);

        for (const auto &entity: element.second.second) {
            entityManager.addEntity(entity);
        }
    }
}

EntityManager& World::addEntityManager(const std::string& nameEntityManager) {
    std::unique_ptr<EntityManager> newEntityManager = std::make_unique<EntityManager>();
    if (!newEntityManager->init()) {
        throw std::runtime_error("Echec de l'initialisation de EntityManager : " + nameEntityManager);
    }
    EntityManager *comp = newEntityManager.get();
    entitiesManager.insert(std::make_pair(nameEntityManager, std::move(newEntityManager)));
    entityManagerMap.insert(std::make_pair(nameEntityManager, comp));
    return *comp;
}

EntityManager& World::getEntityManager(const std::string& nameEntityManager) {
    auto it = entityManagerMap.find(nameEntityManager);
    if (it != entityManagerMap.end()) {
        auto ptr = entityManagerMap[nameEntityManager];
        return *static_cast<EntityManager*>(ptr);
    } else {
        auto& newEntityManager = this->addEntityManager(nameEntityManager);
        return newEntityManager;
    }
}

void World::setNameWorld(std::string newName) {
    nameWorld = std::move(newName);
}

std::string World::getNameWorld() const {
    return nameWorld;
}

std::map<std::string, EntityManager*> World::getEntityManagerMap() const {
    return entityManagerMap;
}

std::map<std::string, EntityManager*> World::getEntitiesManager() const {
    std::map<std::string, EntityManager*> result;

    for (auto const& entityManager : entitiesManager) {
        result[entityManager.first] = entityManager.second.get();
    }
    return result;
}