//
// Created by thibaultcampagne on 19/12/23.
//

#ifndef R_TYPE_ENTITYMANAGER_H
#define R_TYPE_ENTITYMANAGER_H

#include <string>
#include <utility>
#include <vector>
#include <map>
#include "entity.h"

class EntityManager: private Entity{
private:
    std::map<std::string, std::unique_ptr<Entity>> entities{};
    Entity::EntityMap entityMap;
public:
    EntityManager() = default;

    ~EntityManager() = default;

    template<typename T, typename... TArgs>
    T& addEntity(TArgs&&... args);

    template<typename T>
    T& getEntity(std::string nameEntity);
};

#include "entityManager.cpp"


#endif //R_TYPE_ENTITYMANAGER_H
