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


class EntityManager: protected Entity{
private:
    std::map<std::string, std::unique_ptr<Entity>> entities{};
    Entity::EntityMap entityMap;
public:
    /// @brief Default EntityManager constructor.
    /// @param void
    /// @return void
    EntityManager() = default;

    /// @brief EntityManager destructor
    /// @param void
    /// @return void
    ~EntityManager() = default;

    /// @brief addEntity(): Create and add a new entity to the entity manager.
    /// @tparam T: Type of the entity.
    /// @tparam TArgs: Type of the arguments.
    /// @param args: Arguments of the entity.
    template <typename T, typename... TArgs>
    T &addEntity(TArgs &&...args);

    /// @brief getEntity(): Get an entity from the entity manager by its name.
    /// @tparam T: Type of the entity.
    /// @param nameEntity: Name of the entity.
    /// @return T&: Reference of the entity.
    template <typename T>
    T &getEntity(std::string nameEntity);

    bool init() override {return true;}
};

#include "entityManager.cpp"

#endif // R_TYPE_ENTITYMANAGER_H
