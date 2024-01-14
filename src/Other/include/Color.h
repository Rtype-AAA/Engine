//
// Created by thibaultcampagne on 12/01/24.
//

#pragma once

#include "sfml.h"

/**
 * @brief Color class: Color is a class that use for the color in game.
 *
 * The Color class manages the color.
 */

class Color {
private:
    sf::Uint8 red; /// < Represent the Red of a color between 0 and 255.
    sf::Uint8 green; /// < Represent the Green of a color between 0 and 255.
    sf::Uint8 blue; /// < Represent the Blue of a color between 0 and 255.
    sf::Uint8 alpha; /// < Represent the Alpha of a color between 0 and 255.
public:
    /// @brief Default Color constructor.
    ///
    /// Set the default value to "Default" and initialize red, green, blue and alpha to 255 for initialize the color white.
    ///
    /// @param void
    /// @return void
    Color() : red(255), green(255), blue(255), alpha(255) {}

    /// @brief Color constructor with sf::Color& as parameter.
    /// @param sfmlColor: Represent a color preset or no from SFML.
    /// @return void
    explicit Color(const sf::Color& sfmlColor) : red(sfmlColor.r), green(sfmlColor.g), blue(sfmlColor.b), alpha(sfmlColor.a) {}

    /// @brief Default override Color destructor.
    /// @param void
    /// @return void
    ~Color() = default;

    /// @brief getRed(): Get the sf::Uint8 red.
    /// @param void
    /// @return sf::Uint8: The value of red.
    [[nodiscard]] sf::Uint8 getRed() const;

    /// @brief getGreen(): Get the sf::Uint8 green.
    /// @param void
    /// @return sf::Uint8: The value of green.
    [[nodiscard]] sf::Uint8 getGreen() const;

    /// @brief getBlue(): Get the sf::Uint8 blue.
    /// @param void
    /// @return sf::Uint8: The value of blue.
    [[nodiscard]] sf::Uint8 getBlue() const;

    /// @brief getAlpha(): Get the sf::Uint8 alpha.
    /// @param void
    /// @return sf::Uint8: The value of alpha.
    [[nodiscard]] sf::Uint8 getAlpha() const;

    /// @brief setRed(int): Set the sf::Uint8 red with an int and convert into sf::Unit8 in the function.
    /// @param newRed: Number between 0 and 255.
    /// @return void
    void setRed(int newRed);

    /// @brief setGreen(int): Set the sf::Uint8 green with an int and convert into sf::Unit8 in the function.
    /// @param newGreen
    /// @return void
    void setGreen(int newGreen);

    /// @brief setBlue(int): Set the sf::Uint8 blue with an int and convert into sf::Unit8 in the function.
    /// @param newBlue
    /// @return void
    void setBlue(int newBlue);

    /// @brief setAlpha(int): Set the sf::Uint8 alpha with an int and convert into sf::Unit8 in the function.
    /// @param newAlpha
    /// @return void
    void setAlpha(int newAlpha);

    /// @brief operator sf::Color() const: Convert Color classes into sf::Color
    /// @param void
    /// @return sf::Color: Get the Color in sf::Color
    explicit operator sf::Color() const;

    /// @brief fromSFMLColor(const sf::Color&): Convert SFML color into Color class.
    /// @param sfColor: The color from SFML
    /// @return Color: Color class.
    static Color fromSFMLColor(const sf::Color& sfColor);

    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Magenta;
    static const Color Cyan;
    static const Color Transparent;
};
