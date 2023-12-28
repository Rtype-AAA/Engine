//
// Created by thibaultcampagne on 19/12/23.
//

#include "entityManager.h"

template<typename T, typename... TArgs>
T& EntityManager::addEntity(TArgs&&... args) {
    T* comp = new T(std::forward<TArgs>(args)...);
    std::unique_ptr<Entity> uptr {comp};
    entities.insert(std::make_pair(comp->getName(), std::move(uptr)));
    if (comp->init()) {
        entityMap.insert(std::make_pair(comp->getName(), comp));
        return *comp;
    }
    return *static_cast<T*>(nullptr);
}

template<typename T>
T& EntityManager::getEntity(const std::string nameEntity) {
    auto it = entityMap.find(nameEntity);
    if (it != entityMap.end()) {
        auto ptr = entityMap[nameEntity];
        return *static_cast<T*>(ptr);
    } else {
        this->addEntity<Entity>(nameEntity);
        return this->getEntity<Entity>(nameEntity);
    }
}

std::map<std::string, Entity *> EntityManager::getEntities() const {
    std::map<std::string, Entity *> result;

    for (const auto &entry : entities) {
        result[entry.first] = entry.second.get();
    }
    return result;
}