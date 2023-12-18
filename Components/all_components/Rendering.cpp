//
// Created by thibaultcampagne on 30/11/23.
//

#include "Rendering.h"

sf::Sprite Rendering::getSprite() const {
    return sprite;
}

sf::Texture Rendering::getTexture() const {
    return texture;
}

void Rendering::createSprite(const std::string& texturePath) {
    if (texture.loadFromFile(texturePath)) {
        sprite.setTexture(texture);
    } else {
        std::cerr << "Error: Texture not found" << std::endl;
    }
}

void Rendering::createSprite(const sf::Texture& existingTexture) {
    sprite.setTexture(existingTexture);
}

void Rendering::createSprite() {
    sprite.setTexture(texture);
}

void Rendering::setSprite(const sf::Sprite& sprite) {
    Rendering::sprite = sprite;
}

void Rendering::setTexture(const std::string& texturePath) {
    if (texture.loadFromFile(texturePath)) {
    } else {
        std::cerr << "Error: Texture not found" << std::endl;
    }
}

void Rendering::setTexture(const sf::Texture& existingTexture) {
    texture = existingTexture;
}
