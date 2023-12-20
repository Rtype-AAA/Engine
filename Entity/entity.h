//
// Created by thibaultcampagne on 29/11/23.
//

#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include <string>
#include <utility>
#include <vector>
#include <map>
#include <memory>
#include <array>
#include "../Components/Components.h"
#include "../Archetype/Archetypes.h"

/**
 * @brief Entity class: Entity is a class that represents an entity in the game.
 *
 * The Entity class manages components associated with the entity.
*/
class Entity : private Components {
protected:
    using EntityMap = std::map<std::string, Entity*>;
private:
    std::string name{}; ///< Name of the entity
    std::vector<std::unique_ptr<Components>> components{}; ///< List of components attached to the entity.
    Components::ComponentBitset componentBitset; ///< Bitset to track enabled components.
    Components::ComponentArray componentArray{}; ///< Array of components.
public:
    /// @brief Default Entity constructor
    /// @param void
    /// @return void
    Entity() = default;

    /// @brief Entity constructor
    /// @param nameEntity: name of the entity
    /// @param newArchetype: archetype of the entity (optional, default = new archetype)
    /// @return void
    explicit Entity(std::string nameEntity, Archetypes newArchetype = Archetypes()) {
        name = std::move(nameEntity);
    }

    /// @brief Entity destructor
    /// @param void
    /// @return void
    ~Entity() override = default;

    bool init() override {return true;}

    /// @brief genName(): Get the name of the entity
    /// @param void
    /// @return std::string: name of the entity
    [[nodiscard]] std::string getName() const;

    /// @brief setName(): Set the name of the entity
    /// @param newName: new name of the entity
    /// @return void
    void setName(std::string newName);

    /// @brief addComponent(): Add a component to the entity
    /// @tparam T: Type of the component
    /// @tparam TArgs: Variadic template for component constructor arguments.
    /// @param args: arguments of the component
    /// @return T&: reference of the component
    template<typename T, typename... TArgs>
    T& addComponent(TArgs&&... args);

    /// @brief getComponent(): Get a component from the entity
    /// @tparam T: Type of the component
    /// @param void
    /// @return T&: reference of the component
    template<typename T>
    T& getComponent();
};

#include "entity.cpp"

#endif //ENGINE_ENTITY_H
