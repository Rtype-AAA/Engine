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

/**
 * @brief EntityManager class: EntityManager is a class that represents an entity manager in the game.
 *
 * The EntityManager class manages entities.
 */
class EntityManager : private Entity
{
private:
    std::map<std::string, std::unique_ptr<Entity>> entities{}; ///< List of entities present in manager.
    Entity::EntityMap entityMap; ///< Map of entities present in manager.

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

    /// @brief getEntities(): Get the EntityManager's entities.
    /// @param void
    /// @return std::map<std::string, Entity *>: Entities.
    std::map<std::string, Entity *> getEntities() const {
        std::map<std::string, Entity *> result;

        for (const auto &entry : entities) {
            result[entry.first] = entry.second.get();
        }
        return result;
    }

    /// @brief getEntityMap(): Get the EntityManager's entity map.
    /// @param void
    /// @return Entity::EntityMap: Entity map.
    Entity::EntityMap getEntityMap() const {
        return entityMap;
    }
};

#include "entityManager.cpp"

#endif // R_TYPE_ENTITYMANAGER_H
