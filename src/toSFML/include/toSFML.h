//
// Created by thibaultcampagne on 10/01/24.
//

#pragma once

#include "sfml.h"
#include "Rect.h"

class toSFML {
public:
    toSFML() = default;

    ~toSFML() = default;

    template<typename T>
    sf::Rect<T> toSFMLRect(Rect<T> rect);
};

extern template sf::Rect<int> toSFML::toSFMLRect(Rect<int> rect);
extern template sf::Rect<float> toSFML::toSFMLRect(Rect<float> rect);
