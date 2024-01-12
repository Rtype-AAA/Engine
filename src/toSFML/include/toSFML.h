//
// Created by thibaultcampagne on 10/01/24.
//

#pragma once

#include "sfml.h"
#include "Rect.h"

/**
 * @brief toSFML class: toSFML is a class that convert some class into SFML class.
 *
 * Convert some class in SFML class.
 */
class toSFML {
public:
    /// @brief Default toSFML constructor
    /// @param void
    /// @return void
    toSFML() = default;

    /// @brief toSFML destructor.
    /// @param void
    /// @return void
    ~toSFML() = default;

    /// @brief toSFMLRect(): Convert your Rect<T> into sf::Rect<T>.
    /// @tparam T: Type of the rect.
    /// @param rect: The rect you want to convert.
    /// @return sf:Rect<T>: SFML rect.
    template<typename T>
    sf::Rect<T> toSFMLRect(Rect<T> rect);
};

extern template sf::Rect<int> toSFML::toSFMLRect(Rect<int> rect);
extern template sf::Rect<float> toSFML::toSFMLRect(Rect<float> rect);
