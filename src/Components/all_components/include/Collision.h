// Collision.h
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
    bool initCollision();
};