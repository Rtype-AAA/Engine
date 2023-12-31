//
// Created by thibaultcampagne on 30/12/23.
//

#ifndef R_TYPE_DRAWABLECOMPONENT_H
#define R_TYPE_DRAWABLECOMPONENT_H

#include <SFML/Graphics.hpp>

class DrawableComponent {
public:
    virtual ~DrawableComponent() = default;

    virtual void draw(sf::RenderWindow& window) const = 0;
};

#endif //R_TYPE_DRAWABLECOMPONENT_H
