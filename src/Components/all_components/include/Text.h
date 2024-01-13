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

class Text : public Transform, public DrawableComponent {
private:
    sf::Text text;
    sf::Font currentFont;
    std::string stringText;
    int size;
    Color currentColorFill;
    Color currentColorOutline;
    std::function<void()> deferredText;

    Transform* transform;

    int bit = 4;
public:
    Text() : transform{nullptr} {}

    ~Text() = default;

    int getBit() const {return bit;}

    void draw(sf::RenderWindow& window) const override;

    void update(sf::Time deltaTime) override;

    void setText(std::map<std::string, std::shared_ptr<sf::Font>> mapFont, std::string nameFont, std::string newStringText,
                 int sizeText, Color color);

    void setText(std::map<std::string, std::shared_ptr<sf::Font>> mapFont, std::string nameFont, std::string newStringText,
                 int sizeText, Color newColorFill, Color newColorOutline);

    void setFont(std::map<std::string, std::shared_ptr<sf::Font>> mapFont, std::string nameFont);

    void setString(std::string nameText);

    void setSize(int sizeText);

    void setOutlineColor(Color color);

    void setFillColor(Color color);

    void setPosition(Vector2<float> position);

    void setRotation(float rotation);

    void setScale(Vector2<float> scale);

    sf::Text getText() const {return text;}

    sf::Font getFont() const {return currentFont;}

    std::string getStringText() const {return stringText;}

    int getSize() const {return size;}

    Color getColorFill() const {return currentColorFill;}

    Color getColorOutline() const {return currentColorOutline;}

    Transform* getTransform() const {return transform;}

    void setTransform(Transform& newTransform);

    void setDeferredText(std::function<void()> setter);

    void applyDeferredText();
};
