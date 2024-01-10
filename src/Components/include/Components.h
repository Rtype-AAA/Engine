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
    virtual bool init() {return true;}
    virtual void update(sf::Time timeDelta) = 0;
};

