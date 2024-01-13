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
#include "Vector2.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"

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
    std::bitset<6> componentBitset; ///< Bitset to track enabled components.
    std::array<Components*, 6> componentArray{}; ///< Array of components.

    std::function<void()> deferredEntity{};

    bool active{};
public:
    /// @brief Default Entity constructor
    /// @param void
    /// @return void
    Entity() : active(true) {}

    /// @brief Entity constructor
    /// @param nameEntity: name of the entity
    /// @param newArchetype: archetype of the entity (optional, default = new archetype)
    /// @return void
    explicit Entity(const std::string& nameEntity, Archetypes newArchetype = Archetypes());

    /// @brief Entity destructor
    /// @param void
    /// @return void
    ~Entity() override = default;

    /// @brief getBit(): Get the bit of the Sprite.
    /// @param void
    /// @return int: The bit of the Sprite.
    int getBit() override;

    /// @brief init(): Initialize the entity
    /// @param void
    /// @return bool: true if the entity is initialized, false otherwise
    bool init() override;

    /// @brief genName(): Get the name of the entity
    /// @param void
    /// @return std::string: name of the entity
    [[nodiscard]] std::string getName() const;

    /**
     * @brief update(sf::Time): Update the component Music
     * @param timeDelta: sf::Time of the game.
     */
    void update(sf::Time deltaTime) override;

    /// @brief setName(): Set the name of the entity
    /// @param newName: new name of the entity
    /// @return void
    void setName(std::string newName);

    /// @brief addDrawable(): Add a drawable component to the entity
    /// @param component: component to add
    /// @return void
    void addDrawable(Components* component);

    /// @brief removeDrawable(): Remove a drawable component to the entity
    /// @param component: component to remove
    /// @return void
    void removeDrawable(Components* component);

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

    /// @brief removeComponent(): Remove a component to the entity
    /// @tparam T: Type of the component
    /// @return T&: reference of the component
    template<typename T>
    bool removeComponent();

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
    /// @return std::bitset<6>: bitset of the components
    [[nodiscard]] std::bitset<6> getComponentBitset() const;

    /// @brief getDrawableComponents(): Get the drawable components of the entity
    /// @param void
    /// @return std::vector<DrawableComponent*>: drawable components of the entity
    [[nodiscard]] std::vector<DrawableComponent*> getDrawableComponents() const;

    /// @brief getComponentArrays(): Get the array of components
    /// @param void
    /// @return std::array<Components*, 6>: array of components
    [[nodiscard]] std::array<Components*, 6> getComponentArrays() const;

    /**
     * @brief setActive(bool): Set the value active for using entity or not
     * @param isActive: True or false;
     */
    void setActive(bool isActive);

    /**
     * @brief getActive(): Get the value active for knowing if entity is using or not.
     * @return bool: True if the engine use this entity, false otherwise.
     */
    [[nodiscard]] bool getActive() const;

    /**
    * @brief setDeferredEntity(std::function<void()>): Set the deferred entity.
    * @param setter: Function that will set the entity.
    */
    void setDeferredEntity(std::function<void()> setter);

    /**
    * @brief setDeferredEntity(std::function<void()>): Set the deferred entity.
    * @param setter: Function that will set the entity.
    */
    void applyDeferredEntity();

};

extern template Transform& Entity::addComponent<Transform>();
extern template bool Entity::removeComponent<Transform>();
extern template Transform& Entity::getComponent<Transform>();
extern template std::size_t Entity::getComponentTypeID<Transform>();

extern template Sprite& Entity::addComponent<Sprite>();
extern template bool Entity::removeComponent<Sprite>();
extern template Sprite& Entity::getComponent<Sprite>();
extern template std::size_t Entity::getComponentTypeID<Sprite>();

extern template Music& Entity::addComponent<Music>();
extern template bool Entity::removeComponent<Music>();
extern template Music& Entity::getComponent<Music>();
extern template std::size_t Entity::getComponentTypeID<Music>();

extern template Sound& Entity::addComponent<Sound>();
extern template bool Entity::removeComponent<Sound>();
extern template Sound& Entity::getComponent<Sound>();
extern template std::size_t Entity::getComponentTypeID<Sound>();

extern template Text& Entity::addComponent<Text>();
extern template bool Entity::removeComponent<Text>();
extern template Text& Entity::getComponent<Text>();
extern template std::size_t Entity::getComponentTypeID<Text>();

