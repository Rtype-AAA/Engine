//
// Created by thibaultcampagne on 12/01/24.
//

#include "Color.h"

sf::Uint8 Color::getRed() const {
    return red;
}

sf::Uint8 Color::getGreen() const {
    return green;
}

sf::Uint8 Color::getBlue() const {
    return blue;
}

sf::Uint8 Color::getAlpha() const {
    return alpha;
}

void Color::setRed(int newRed) {
    red = newRed;
}

void Color::setGreen(int newGreen) {
    green = newGreen;
}

void Color::setBlue(int newBlue) {
    blue = newBlue;
}

void Color::setAlpha(int newAlpha) {
    alpha = newAlpha;
}

Color::operator sf::Color() const {
    return {red, green, blue, alpha};
}

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