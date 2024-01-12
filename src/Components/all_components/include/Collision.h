
#pragma once

#include "Sprite.h"

/**
 * @brief Collision class: Handles collision detection between two entities.
 */
class Collision : public Components, public Sprite {
private:
    int bit = 3; ///< Bit of the Collision.
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
    bool initCollision() const {return true;}

/// @brief checkCollision(): Check if two sprites are colliding.
    /// @param sprite1: First sprite.
    /// @param sprite2: Second sprite.
    /// @return bool: True if sprites are colliding, false otherwise.
    static bool checkCollision(const Sprite& sprite1, const Sprite& sprite2);
};
