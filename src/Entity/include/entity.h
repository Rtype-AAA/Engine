//
// Created by thibaultcampagne on 29/11/23.
//

#pragma once

#include "std.h"
#include "Components.h"
#include "DrawableComponent.h"
#include "Archetypes.h"
#include "Sprite.h"
#include "Transform.h"

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
    bool initEntity();

    /// @brief genName(): Get the name of the entity
    /// @param void
    /// @return std::string: name of the entity
    [[nodiscard]] std::string getName() const;

    void update(sf::Time deltaTime) override;

    /// @brief setName(): Set the name of the entity
    /// @param newName: new name of the entity
    /// @return void
    void setName(std::string newName);

    /// @brief addDrawable(): Add a drawable component to the entity
    /// @param component: component to add
    /// @return void
    void addDrawable(Components* component);

    /// @brief drawEntity(): Draw the entities
    /// @param window: window where the entities are drawn
    /// @return void
    void drawEntity(sf::RenderWindow& window);

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

    /// @brief getComponentTypeID(): Get the ID of a component
    /// @tparam T: Type of the component
    /// @param void
    /// @return std::size_t: ID of the component
    template<typename T>
    std::size_t getComponentTypeID() noexcept;

    /// @brief getComponentBitset(): Get the bitset of the components
    /// @param void
    /// @return std::bitset<3>: bitset of the components
    std::bitset<3> getComponentBitset() const {return componentBitset;}

    /// @brief getDrawableComponents(): Get the drawable components of the entity
    /// @param void
    /// @return std::vector<DrawableComponent*>: drawable components of the entity
    std::vector<DrawableComponent*> getDrawableComponents() const {return drawableComponents;}

    /// @brief getComponentArrays(): Get the array of components
    /// @param void
    /// @return std::array<Components*, 3>: array of components
    std::array<Components*, 3> getComponentArrays() const {return componentArray;}
};

extern template std::size_t Entity::getComponentTypeID<Sprite>();
extern template std::size_t Entity::getComponentTypeID<Transform>();

extern template Transform& Entity::addComponent<Transform>();
extern template Transform& Entity::addComponent<Transform>(std::map<std::string, std::vector<float>>&);
extern template Sprite& Entity::addComponent<Sprite>();
extern template Sprite& Entity::addComponent<Sprite>(std::string&);

extern template Transform& Entity::getComponent<Transform>();
extern template Sprite& Entity::getComponent<Sprite>();
