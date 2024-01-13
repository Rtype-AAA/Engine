//
// Created by thibaultcampagne on 12/01/24.
//

#include "Text.h"

int Text::getBit() const {
    return bit;
}

void Text::draw(sf::RenderWindow &window) const {
    window.draw(text);
}

void Text::update(sf::Time deltaTime) {
    text.setPosition(transform->getPosition().getX(), transform->getPosition().getY());
    text.setRotation(transform->getRotation());
    text.setScale(transform->getScale().getX(), transform->getScale().getY());
}

bool Text::init() {
    return true;
}

void Text::setText(std::map <std::string, std::shared_ptr<sf::Font>> mapFont, const std::string& nameFont,
                   const std::string& newStringText, int sizeText, Color fillColor) {
    if (!mapFont.empty()) {
        auto it = mapFont.find(nameFont);
        if (it != mapFont.end()) {
            text.setFont(*it->second);
            currentFont = *it->second;
            text.setString(newStringText);
            stringText = newStringText;
            text.setCharacterSize(sizeText);
            size = sizeText;
            text.setFillColor(static_cast<sf::Color>(fillColor));
            currentColorFill = fillColor;
        }
    }
}

void Text::setText(std::map <std::string, std::shared_ptr<sf::Font>> mapFont, const std::string& nameFont,
                   const std::string& newStringText, int sizeText, Color fillColor, Color outlineColor) {
    if (!mapFont.empty()) {
        auto it = mapFont.find(nameFont);
        if (it != mapFont.end()) {
            text.setFont(*it->second);
            currentFont = *it->second;
            text.setString(newStringText);
            stringText = newStringText;
            text.setCharacterSize(sizeText);
            size = sizeText;
            text.setFillColor(static_cast<sf::Color>(fillColor));
            currentColorFill = fillColor;
            text.setOutlineColor(static_cast<sf::Color>(outlineColor));
            currentColorOutline = outlineColor;
        }
    }
}

void Text::setFont(std::map <std::string, std::shared_ptr<sf::Font>> mapFont, const std::string& nameFont) {
    if (!mapFont.empty()) {
        auto it = mapFont.find(nameFont);
        if (it != mapFont.end()) {
            text.setFont(*it->second);
            currentFont = *it->second;
        }
    }
}

void Text::setString(const std::string& newStringText) {
    text.setString(newStringText);
    stringText = newStringText;
}

void Text::setSize(int sizeText) {
    text.setCharacterSize(sizeText);
    size = sizeText;
}

void Text::setOutlineColor(Color outlineColor) {
    text.setOutlineColor(static_cast<sf::Color>(outlineColor));
    currentColorOutline = outlineColor;
}

void Text::setFillColor(Color fillColor) {
    text.setFillColor(static_cast<sf::Color>(fillColor));
    currentColorFill = fillColor;
}

sf::Text Text::getText() const {
    return text;
}

sf::Font Text::getFont() const {
    return currentFont;
}

std::string Text::getStringText() const {
    return stringText;
}

int Text::getSize() const {
    return size;
}

Color Text::getColorFill() const {
    return currentColorFill;
}

Color Text::getColorOutline() const {
    return currentColorOutline;
}

Transform* Text::getTransform() {
    return transform;
}

void Text::setTransform(Transform& newTransform) {
    transform = &newTransform;
}

void Text::setDeferredText(std::function<void()> setter) {
    deferredText = std::move(setter);
}

void Text::applyDeferredText() {
    if (deferredText) {
        deferredText();
    }
}