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

bool Rendering::createSprite(const std::string& texturePath) {
    if (texture.loadFromFile(texturePath)) {
        sprite.setTexture(texture);
        return true;
    } else {
        std::cerr << "Error: Texture not found" << std::endl;
        return false;
    }
}

bool Rendering::createSprite(const sf::Texture& existingTexture) {
    sprite.setTexture(existingTexture);
    return true;
}

bool Rendering::createSprite() {
    sprite.setTexture(texture);
    return true;
}

bool Rendering::setSprite(const sf::Sprite& sprite) {
    Rendering::sprite = sprite;
    return true;
}

bool Rendering::setTexture(const std::string& texturePath) {
    if (texture.loadFromFile(texturePath)) {
        sprite.setTexture(texture);
        return true;
    } else {
        std::cerr << "Error: Texture not found" << std::endl;
        return false;
    }
}

bool Rendering::setTexture(const sf::Texture& existingTexture) {
    texture = existingTexture;
    sprite.setTexture(texture);
    return true;
}
