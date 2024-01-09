//
// Created by thibaultcampagne on 30/12/23.
//

#pragma once

#include "sfml.h"

/**
 * @brief DrawableComponent class: DrawableComponent is a class that represents a drawable component in the game.
 *
 * DrawableComponents are components that can be drawn on the screen.
 */
class DrawableComponent {
public:
    /// @brief Default DrawableComponent constructor
    /// @param void
    /// @return void
    virtual ~DrawableComponent() = default;

    /// @brief draw(): Draw the component
    /// @param window: Window to draw the component on
    /// @return void
    virtual void draw(sf::RenderWindow& window) const = 0;
};

