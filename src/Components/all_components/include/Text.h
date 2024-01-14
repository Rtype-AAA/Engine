//
// Created by thibaultcampagne on 12/01/24.
//

#pragma once

#include "sfml.h"
#include "Components.h"
#include "Transform.h"
#include "Vector2.h"
#include "std.h"
#include "Color.h"
#include "DrawableComponent.h"
#include "ITransform.h"

/**
 * @brief Text class: Text is a class that represents the text in the world.
 *
 * The text class manages the text from an Entity using SFML.
 */

class Text : public Transform, public DrawableComponent, public ITransform {
private:
    sf::Text text; /// < SFML text.
    sf::Font currentFont; /// < Current SFML Font.
    std::string stringText; /// < String of the Text.
    int size{}; /// < Size of the Text.
    Color currentColorFill; /// < Current Fill Color of the Text.
    Color currentColorOutline; /// < Current Outline Color of the Text.
    std::function<void()> deferredText; /// < Deferred function for Text.

    Transform* transform; /// < Reference of the component Transform.

    int bit = 4; /// < Bit of the Text.
public:
    /// @brief Default Text constructor.
    /// @param void
    /// @return void
    Text() : transform{nullptr} {}

    /// @brief Default override Text destructor.
    /// @param void
    /// @return void
    ~Text() override = default;

    /// @brief getBit(): Get the bit of the Text.
    /// @param void
    /// @return int: The bit of the Text.
    int getBit() override;

    /// @brief draw(): Draw the Text.
    /// @param window: SFML RenderWindow where the Text will be drawn.
    /// @return void
    void draw(sf::RenderWindow& window) const override;

    /// @brief update(sf::Time): Update the component Text
    /// @param timeDelta: sf::Time of the game.
    /// @return void
    void update(sf::Time deltaTime) override;

    /// @brief init(): Initialize the component.
    /// @param void
    /// @return bool: true if the component is initialized, false otherwise. If no Transform is set, returns false.
    bool init() override;

    /// @brief Sets the text of the component.
    ///
    /// This function sets the Text of the component using the provided font map, the font name,
    /// a string for set the Text, the size for the size of character and fill color for color the text.
    ///
    /// @param mapFont: Map of all the font loaded.
    /// @param nameFont: Name of the font loaded.
    /// @param newStringText: String text for draw.
    /// @param sizeText: Size of the text.
    /// @param fillColor: Color for the text.
    /// @return void
    void setText(std::map<std::string, std::shared_ptr<sf::Font>> mapFont, const std::string& nameFont, const std::string& newStringText,
                 int sizeText, Color fillColor);

    /// @brief Sets the text of the component.
    ///
    /// This function sets the Text of the component using the provided font map, the font name,
    /// a string for set the Text, the size for the size of character, fill color for color the text and outline
    /// color for the border of the text.
    ///
    /// @param mapFont: Map of all the font loaded.
    /// @param nameFont: Name of the font loaded.
    /// @param newStringText: String text for draw.
    /// @param sizeText: Size of the text.
    /// @param fillColor: Color for the text.
    /// @param outlineColor: Color for the border of the text.
    /// @return void
    void setText(std::map<std::string, std::shared_ptr<sf::Font>> mapFont, const std::string& nameFont, const std::string& newStringText,
                 int sizeText, Color fillColor, Color outlineColor);

    /// @brief setFont(std::map<std::string, std::shared_ptr<sf::Font>>, const std::string&): Set the font of Text.
    /// @param mapFont: Map of all the font loaded.
    /// @param nameFont: Name of the font loaded.
    /// @return void
    void setFont(std::map<std::string, std::shared_ptr<sf::Font>> mapFont, const std::string& nameFont);

    /// @brief setString(const std::string&): Set the string of Text.
    /// @param newStringText: String text for draw.
    /// @return void
    void setString(const std::string& newStringText);

    /// @brief setSize(int): Set the size of Text.
    /// @param sizeText: Size of the text.
    /// @return void
    void setSize(int sizeText);

    /// @brief setOutlineColor(Color): Set the outline color of Text.
    /// @param outlineColor: Color for the border of the text.
    /// @return void
    void setOutlineColor(Color outlineColor);

    /// @brief setFillColor(Color): Set the fill color of Text.
    /// @param fillColor: Color for the text.
    /// @return void
    void setFillColor(Color fillColor);


    /// @brief getText(): Get the Text.
    /// @param void
    /// @return sf::Text: Text for draw.
    sf::Text getText() const;

    /// @brief getFont(): Get the Font.
    /// @param void
    /// @return sf::Font: Font of the Text.
    sf::Font getFont() const;

    /// @brief getStringText(): Get the string.
    /// @param void
    /// @return std::string: String of the text.
    std::string getStringText() const;

    /// @brief getSize(): Get the size.
    /// @param void
    /// @return int: int number that represents size of the text.
    int getSize() const;

    /// @brief getColorFill(): Get the fill color.
    /// @param void
    /// @return Color: Fill color of the text.
    Color getColorFill() const;

    /// @brief getColorOutline(): Get the outline color.
    /// @param void
    /// @return Color: Outline color of the text.
    Color getColorOutline() const;

    /// @brief getTransform(): Get the reference to the component Transform.
    /// @param void
    /// @return Transform*: Reference of Transform
    Transform* getTransform() override;

    /// @brief setTransform(Transform&): Set the reference of the Transform component.
    /// @param newTransform: Reference of Transform.
    /// @return void
    void setTransform(Transform& newTransform);

    /// @brief setDeferredText(std::function<void()>): Set the deferred text.
    /// @param setter: Function that will set the text.
    /// @return void
    void setDeferredText(std::function<void()> setter);

    /// @brief applyDeferredText(): Apply the deferred text.
    /// @param void
    /// @return void
    void applyDeferredText();
};
