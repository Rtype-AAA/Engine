//
// Created by thibaultcampagne on 19/12/23.
//

#pragma  once

#include "std.h"
#include "entity.h"
#include "DrawableComponent.h"


class EntityManager: protected Entity {
private:
    std::map<std::string, std::unique_ptr<Entity>> entities{}; ///< Map of the pointers of the present entities in the game.
    std::map<std::string, Entity*> entityMap; ///< Map of the present entities in the game.
public:
    /// @brief Default EntityManager constructor.
    /// @param void
    /// @return void
    EntityManager() = default;

    /// @brief EntityManager destructor
    /// @param void
    /// @return void
    ~EntityManager() override = default;

    /// @brief initEntityManager(): Initialize the EntityManager.
    /// @param void
    /// @return bool: true if the EntityManager is initialized, false otherwise.
    bool init() override;

    /// @brief addEntity(): Create and add a new entity to the entity manager.
    /// @tparam T: Type of the entity.
    /// @tparam TArgs: Type of the arguments.
    /// @param args: Arguments of the entity.
    Entity &addEntity(const std::string& nameEntity, Archetypes newArchetype = Archetypes());

    /// @brief getEntity(): Get an entity from the entity manager by its name.
    /// @tparam T: Type of the entity.
    /// @param nameEntity: Name of the entity.
    /// @return T&: Reference of the entity.
    Entity &getEntity(const std::string& nameEntity);

    /// @brief getEntities(): Get the EntityManager's entities.
    /// @param void
    /// @return std::map<std::string, Entity *>: Entities.
    [[nodiscard]] std::map<std::string, Entity *> getEntities() const;

    /// @brief getEntityMap(): Get the EntityManager's entity map.
    /// @param void
    /// @return Entity::EntityMap: Entity map.
    [[nodiscard]] std::map<std::string, Entity*> getEntityMap() const;
};
