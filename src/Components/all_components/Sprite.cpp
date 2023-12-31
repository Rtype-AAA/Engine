//
// Created by thibaultcampagne on 30/11/23.
//

#include "Sprite.h"

void Sprite::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::Sprite Sprite::getSprite() const {
    return sprite;
}

sf::Texture Sprite::getTexture() const {
    return texture;
}

void Sprite::createSprite(const std::string& texturePath) {
    if (texture.loadFromFile(texturePath)) {
        sprite.setTexture(texture);
    } else {
        std::cerr << "Error: Texture not found" << std::endl;
    }
}

void Sprite::createSprite(const sf::Texture& existingTexture) {
    sprite.setTexture(existingTexture);
}

void Sprite::createSprite() {
    sprite.setTexture(texture);
}

void Sprite::setSprite(const sf::Sprite& newSprite) {
    sprite = newSprite;
}

void Sprite::setSprite(std::map<std::string, sf::Texture> mapTexture, std::string nameTexture,
                       std::map<std::string, std::vector<float>>& mapTransform) {
    texture = mapTexture.find(nameTexture)->second;
    sprite.setTexture(texture);
    auto position = mapTransform.find("Position");
    if (position != mapTransform.end()) {
        sprite.setPosition(position->second[0], position->second[1]);
    }
    auto scale = mapTransform.find("Scale");
    if (scale != mapTransform.end()) {
        sprite.setScale(scale->second[0], scale->second[1]);
    }
}

void Sprite::applyDeferredSprite() {
    if (deferredSprite) {
        deferredSprite();
    }
}

void Sprite::setDeferredSprite(std::function<void()> setter) {
    deferredSprite = setter;
}

void Sprite::setTexture(const sf::Texture& existingTexture) {
    texture = existingTexture;
}
