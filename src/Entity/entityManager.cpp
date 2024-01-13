//
// Created by thibaultcampagne on 19/12/23.
//

#include "entityManager.h"

bool EntityManager::init() {
    return true;
}

Entity& EntityManager::addEntity(const std::string& nameEntity, Archetypes newArchetype) {
    std::unique_ptr<Entity> newEntity = std::make_unique<Entity>(nameEntity, newArchetype);
    if (!newEntity->init()) {
        throw std::runtime_error("Echec de l'initialisation de Entity : " + nameEntity);
    }
    Entity *comp = newEntity.get();
    entities.insert(std::make_pair(nameEntity, std::move(newEntity)));
    entityMap.insert(std::make_pair(nameEntity, comp));
    return *comp;
}

Entity& EntityManager::getEntity(const std::string& nameEntity) {
    auto it = entityMap.find(nameEntity);
    if (it != entityMap.end()) {
        auto ptr = entityMap[nameEntity];
        return *static_cast<Entity*>(ptr);
    } else {
        auto& newEntity = this->addEntity(nameEntity);
        return newEntity;
    }
}

std::map<std::string, Entity *> EntityManager::getEntities() const {
    std::map<std::string, Entity *> result;

    for (const auto &entity : entities) {
        result[entity.first] = entity.second.get();
    }
    return result;
}

std::map<std::string, Entity*> EntityManager::getEntityMap() const {
    return entityMap;
}