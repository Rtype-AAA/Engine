//
// Created by thibaultcampagne on 10/01/24.
//

#include "toSFML.h"

template<typename T>
sf::Rect<T> toSFML::toSFMLRect(Rect<T> rect) {
    return sf::Rect<T>(rect.getLeft(), rect.getTop(), rect.getWidth(), rect.getHeight());
}

template sf::Rect<int> toSFML::toSFMLRect(Rect<int> rect);
template sf::Rect<float> toSFML::toSFMLRect(Rect<float> rect);
