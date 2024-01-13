//
// Created by thibaultcampagne on 12/01/24.
//

#pragma once

#include "sfml.h"

class Color {
private:
    int red;
    int green;
    int blue;
    int alpha;
public:
    Color() : red(255), green(255), blue(255), alpha(255) {}

    ~Color() = default;

    int getRed() const {return red;}
    int getGreen() const {return green;}
    int getBlue() const {return blue;}
    int getAlpha() const {return alpha;}

    void setRed(int newRed);
    void setGreen(int newGreen);
    void setBlue(int newBlue);
    void setAlpha(int newAlpha);

    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Magenta;
    static const Color Cyan;
    static const Color Transparent;

    operator sf::Color() const {return sf::Color(red, green, blue, alpha);}
    static Color fromSFMLColor(const sf::Color& sfColor);
};
