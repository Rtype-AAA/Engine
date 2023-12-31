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
#include "../Components/DrawableComponent.h"
#include "../Archetype/Archetypes.h"

/**
 * @brief Entity class: Entity is a class that represents an entity in the game.
 *
 * The Entity class manages components associated with the entity.
*/
class Entity : protected Components {
private:
    std::string name{}; ///< Name of the entity
    std::vector<DrawableComponent*> drawableComponents{};
    std::vector<std::unique_ptr<Components>> components{}; ///< List of components attached to the entity.
    std::bitset<3> componentBitset; ///< Bitset to track enabled components.
    std::array<Components*, 3> componentArray{}; ///< Array of components.
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

    /// @brief init(): Initialize the entity
    /// @param void
    /// @return bool: true if the entity is initialized, false otherwise
    inline bool init() override;

    /// @brief genName(): Get the name of the entity
    /// @param void
    /// @return std::string: name of the entity
    [[nodiscard]] inline std::string getName() const;

    /// @brief setName(): Set the name of the entity
    /// @param newName: new name of the entity
    /// @return void
    inline void setName(std::string newName);

    inline void addDrawable(Components* component);

    inline void draw(sf::RenderWindow& window);

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

    std::bitset<3> getComponentBitset() const {return componentBitset;}
    std::vector<DrawableComponent*> getDrawableComponents() const {return drawableComponents;}
    std::array<Components*, 3> getComponentArrays() const {return componentArray;}
};

#include "entity.cpp"

#endif //ENGINE_ENTITY_H
