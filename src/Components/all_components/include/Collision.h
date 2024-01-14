
#pragma once

#include "sfml.h"
#include "Components.h"
#include "Sprite.h"

/**
 * @brief Collision class: Handles collision detection between two entities.
 */
class Collision : public Components, public Sprite {
private:
    int bit = 3; ///< Bit of the Collision.
    bool AABB(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
public:
    /// @brief Default Collision constructor.
    /// @param void
    /// @return void
    Collision() = default;

    /// @brief Collision destructor.
    /// @param void
    /// @return void
    ~Collision() override = default;

    // Vérifie la collision entre deux sprites spécifiques

    bool checkSpriteCollision(Sprite& sprite1, Sprite& sprite2, float push);

    // Vérifie les collisions entre toutes les sprites d'une liste
    void checkCollisions(std::vector<std::reference_wrapper<Sprite>>& sprites, float push);
};
