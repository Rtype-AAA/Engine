//
// Created by thibaultcampagne on 12/01/24.
//

#include "Color.h"

Color Color::fromSFMLColor(const sf::Color &sfColor) {
    Color color;
    color.red = sfColor.r;
    color.green = sfColor.g;
    color.blue = sfColor.b;
    color.alpha = sfColor.a;
    return color;
}

const Color Color::Black = Color::fromSFMLColor(sf::Color::Black);
const Color Color::White = Color::fromSFMLColor(sf::Color::White);
const Color Color::Red = Color::fromSFMLColor(sf::Color::Red);
const Color Color::Green = Color::fromSFMLColor(sf::Color::Green);
const Color Color::Blue = Color::fromSFMLColor(sf::Color::Blue);
const Color Color::Yellow = Color::fromSFMLColor(sf::Color::Yellow);
const Color Color::Magenta = Color::fromSFMLColor(sf::Color::Magenta);
const Color Color::Cyan = Color::fromSFMLColor(sf::Color::Cyan);
const Color Color::Transparent = Color::fromSFMLColor(sf::Color::Transparent);