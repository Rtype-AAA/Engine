//
// Created by thibaultcampagne on 12/01/24.
//

#include "Text.h"

void Text::draw(sf::RenderWindow &window) const {
    window.draw(text);
}

void Text::update(sf::Time deltaTime) {
    return;
}

void Text::setText(std::map <std::string, std::shared_ptr<sf::Font>> mapFont, std::string nameFont,
                   std::string newStringText, int sizeText, Color newColor) {
    if (!mapFont.empty()) {
        auto it = mapFont.find(nameFont);
        if (it != mapFont.end()) {
            text.setFont(*it->second);
            currentFont = *it->second;
            text.setString(newStringText);
            stringText = newStringText;
            text.setCharacterSize(sizeText);
            size = sizeText;
            text.setFillColor(static_cast<sf::Color>(newColor));
            currentColorFill = newColor;
        }
    }
}

void Text::setText(std::map <std::string, std::shared_ptr<sf::Font>> mapFont, std::string nameFont,
                   std::string newStringText, int sizeText, Color newFillColor, Color newOutlineColor) {
    if (!mapFont.empty()) {
        auto it = mapFont.find(nameFont);
        if (it != mapFont.end()) {
            text.setFont(*it->second);
            currentFont = *it->second;
            text.setString(newStringText);
            stringText = newStringText;
            text.setCharacterSize(sizeText);
            size = sizeText;
            text.setFillColor(static_cast<sf::Color>(newFillColor));
            currentColorFill = newFillColor;
            text.setOutlineColor(static_cast<sf::Color>(newOutlineColor));
            currentColorOutline = newOutlineColor;
        }
    }
}

void Text::setFont(std::map <std::string, std::shared_ptr<sf::Font>> mapFont, std::string nameFont) {
    if (!mapFont.empty()) {
        auto it = mapFont.find(nameFont);
        if (it != mapFont.end()) {
            text.setFont(*it->second);
            currentFont = *it->second;
        }
    }
}

void Text::setString(std::string newStringText) {
    text.setString(newStringText);
    stringText = newStringText;
}

void Text::setSize(int sizeText) {
    text.setCharacterSize(sizeText);
    size = sizeText;
}

void Text::setOutlineColor(Color color) {
    text.setOutlineColor(static_cast<sf::Color>(color));
    currentColorOutline = color;
}

void Text::setFillColor(Color color) {
    text.setFillColor(static_cast<sf::Color>(color));
    currentColorFill = color;
}

void Text::setPosition(Vector2<float> position) {
    text.setPosition(position.getX(), position.getY());
    transform->setTransformPosition(position);
}

void Text::setRotation(float rotation) {
    text.setRotation(rotation);
    transform->setTransformRotation(rotation);
}

void Text::setScale(Vector2<float> scale) {
    text.setScale(scale.getX(), scale.getY());
    transform->setTransformScale(scale);
}

void Text::setTransform(Transform& newTransform) {
    transform = &newTransform;
}

void Text::setDeferredText(std::function<void()> setter) {
    deferredText = setter;
}

void Text::applyDeferredText() {
    if (deferredText) {
        deferredText();
    }
}