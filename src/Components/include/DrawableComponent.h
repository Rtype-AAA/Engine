//
// Created by thibaultcampagne on 30/12/23.
//

#pragma once

#include "sfml.h"

class DrawableComponent {
public:
    virtual ~DrawableComponent() = default;

    virtual void draw(sf::RenderWindow& window) const = 0;
};

