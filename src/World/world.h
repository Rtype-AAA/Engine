//
// Created by thibaultcampagne on 20/12/23.
//

#ifndef R_TYPE_WORLD_H
#define R_TYPE_WORLD_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include "../Entity/entityManager.h"
#include "../include/all_components.h"

/**
 * @brief World class: World is a class that represents the world of the game.
 *
 * The World class manages the world of the game.
 */
class World: protected EntityManager {
private:
    std::map<std::string, std::unique_ptr<EntityManager>> entitiesManager{}; /// < Map of the entities manager's unique pointers.
    std::map<std::string, EntityManager*> entityManagerMap{}; /// < Map of the entities manager.
    std::string nameWorld{}; /// < Name of the world.
public:
    /// @brief Default World constructor.
    /// @param void
    /// @return void
    World() = default;

    /// @brief World destructor.
    /// @param void
    /// @return void
    ~World() override = default;

    /// @brief createEntities(): Create the entities.
    /// @param mapEntityManager: Map of the entities manager's unique pointers.
    /// @param keyEntityManager: Key of the entities manager.
    /// @return void
    void createEntities(std::map<std::string, std::pair<std::unique_ptr<EntityManager>,
            std::vector<std::string>>>& mapEntityManager, std::string keyEntityManager);

    /// @brief addEntityManager(): Add an entity manager to the map.
    /// @param NameEntityManager: Name of the entity manager.
    /// @return EntityManager&: The entity manager.
    EntityManager& addEntityManager(std::string NameEntityManager);

    /// @brief getEntityManager(): Get the entity manager.
    /// @param NameEntityManager: Name of the entity manager.
    /// @return EntityManager&: The entity manager.
    EntityManager& getEntityManager(std::string NameEntityManager);

    /// @brief setNameWorld(): Set the name of the world.
    /// @param newName: New name of the world.
    /// @return void
    void setNameWorld(std::string newName);

    /// @brief getNameWorld(): Get the name of the world.
    /// @param void
    /// @return std::string: The name of the world.
    std::string getNameWorld() const {return nameWorld;}

    /// @brief getEntityManagerMap(): Get the map of the entity manager.
    /// @param void
    /// @return std::map<std::string, EntityManager*>: The map of the entity manager.
    std::map<std::string, EntityManager*> getEntityManagerMap() const {return entityManagerMap;}

    /// @brief init(): Initialize the World.
    /// @param void
    /// @return bool: True if the world is initialized, false otherwise.
    bool init() override {return true;}
};

#endif //R_TYPE_WORLD_H
