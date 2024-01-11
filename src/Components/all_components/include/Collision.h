// Collision.h
#pragma once

#include "Sprite.h"

/**
 * @brief Collision class: Handles collision detection between two entities.
 */
class Collision : public Components {
private:
    std::shared_ptr<Sprite> sprite; ///< Sprite of the entity.
    sf::FloatRect bounds; ///< Bounds of the entity.
    int bit = 2; ///< Bit of the Collision.
public:
    /// @brief Default Collision constructor.
    /// @param void
    /// @return void
    Collision() = default;

    /// @brief Collision destructor.
    /// @param void
    /// @return void
    ~Collision() override = default;

    /// @brief init(): Initialize the Collision.
    /// @param void
    /// @return bool: True if the Collision is initialized, false otherwise.
    bool initCollision();

    /// @brief getBit(): Get the bit of the Collision.
    /// @param void
    /// @return int: The bit of the Collision.
    int getBit() const {return bit;}

    /// @brief getBounds(): Get the bounds of the Collision.
    /// @param void
    /// @return sf::FloatRect: The bounds of the Collision.
    sf::FloatRect getBounds() const {return bounds;}

    /// @brief setBounds(): Set the bounds of the Collision.
    /// @param bounds: The bounds of the Collision.
    /// @return void
    void setBounds(const sf::FloatRect& bounds) {Collision::bounds = bounds;}

    /// @brief getSprite(): Get the Sprite of the Collision.
    /// @param void
    /// @return std::shared_ptr<Sprite>: The Sprite of the Collision.
    std::shared_ptr<Sprite> getSprite() const {return sprite;}

    /// @brief setSprite(): Set the Sprite of the Collision.
    /// @param sprite: The Sprite of the Collision.
    /// @return void
    void setSprite(const std::shared_ptr<Sprite>& sprite) {Collision::sprite = sprite;}
};