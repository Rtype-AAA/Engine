//
// Created by thibaultcampagne on 20/12/23.
//

#include "world.h"

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

void World::createEntities(std::map<std::string, std::pair<std::unique_ptr<EntityManager>,
        std::vector<std::string>>>& mapEntityManager, std::string keyEntityManager) {
    for (const auto& element : mapEntityManager) {
        const std::string key = element.first;

        if (key == keyEntityManager) {
            auto &entityManager = getEntityManager(key);
            for (const auto &entity: element.second.second) {
                entityManager.addEntity<Entity>(entity);
            }
            break;
        }
    }
}