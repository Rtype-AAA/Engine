//
// Created by thibaultcampagne on 29/11/23.
//

#pragma once

#include "std.h"
#include "sfml.h"

/**
 * @brief Components class: Components is a class that represents a component in the game.
 *
 * Components are the building blocks of the game. They are attached to entities and define their behavior.
 */
class Components {
public:
    /// @brief Default Components constructor
    /// @param void
    /// @return void
    Components() = default;

    /// @brief Components destructor
    /// @param void
    /// @return void
    virtual ~Components() = default;

    /// @brief init(): Initialize the component
    /// @param void
    /// @return bool: true if the component is initialized, false otherwise
    virtual bool init() = 0;

    /// @brief getBit(): Get the bitmask of the component
    /// @param void
    /// @return int: bitmask of the component
    virtual int getBit() = 0;

    /// @brief update(): Update the component
    /// @param timeDelta: time elapsed since the last update
    /// @return void
    virtual void update(sf::Time timeDelta) = 0;
};

