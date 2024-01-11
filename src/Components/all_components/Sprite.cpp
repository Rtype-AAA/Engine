//
// Created by thibaultcampagne on 30/11/23.
//

#include "Sprite.h"

void Sprite::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Sprite::doAnimation(sf::Time deltaTime) {
    timeSinceLastFrame += deltaTime;

    if (timeSinceLastFrame >= frameDuration) {
        timeSinceLastFrame -= frameDuration;
        currentFrame = (currentFrame + 1) % frames.size();
        sprite.setTextureRect(toSFMLRect(frames[currentFrame]));
    }
}

void Sprite::update(sf::Time deltaTime) {
    if (animation) {
        doAnimation(deltaTime);
    }
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

void Sprite::setSprite(std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture, std::string nameTexture,
                       bool animate, std::vector<Rect<int>> newFrames, int durationOfFrame) {
    if (!mapTexture.empty()) {
        auto it = mapTexture.find(nameTexture);
        if (it != mapTexture.end()) {
            sprite.setTexture(*(it->second));
            animation = animate;
            if (animate) {
                if (newFrames.size() > 0) {
                    frames = newFrames;
                    currentFrame = 0;
                    timeSinceLastFrame = sf::Time::Zero;
                    frameDuration = sf::milliseconds(durationOfFrame);
                    sprite.setTextureRect(toSFMLRect(frames[0]));
                }
            }
        }
//        auto position = mapTransform.find("Position");
//        if (position != mapTransform.end()) {
//            sprite.setPosition(position->second[0], position->second[1]);
//        }
//        auto scale = mapTransform.find("Scale");
//        if (scale != mapTransform.end()) {
//            sprite.setScale(scale->second[0], scale->second[1]);
//        }
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


void Sprite::setTransformSprite() {
    if (transform) {
        sprite.setPosition(transform->getTransformStruct().position.getX(),
                           transform->getTransformStruct().position.getY());
        sprite.setRotation(transform->getTransformStruct().rotation);
        sprite.setScale(transform->getTransformStruct().scale.getX(), transform->getTransformStruct().scale.getY());
    }
}

void Sprite::setTransformSprite(Vector2<float> newPosition, float newRotation, Vector2<float> newScale) {
    if (transform) {
        sprite.setPosition(newPosition.getX(), newPosition.getY());
        sprite.setRotation(newRotation);
        sprite.setScale(newScale.getX(), newScale.getY());
        transform->setTransform(newPosition, newRotation, newScale);
    }
}

void Sprite::setPosition() {
    if (transform) {
        sprite.setPosition(transform->getTransformStruct().position.getX(),
                           transform->getTransformStruct().position.getY());
    }
}

void Sprite::setPosition(Vector2<float> newPosition) {
    if (transform) {
        sprite.setPosition(newPosition.getX(), newPosition.getY());
        transform->setTransformPosition(newPosition);
    }
}

void Sprite::setRotation() {
    if (transform) {
        sprite.setRotation(transform->getTransformStruct().rotation);
    }
}

void Sprite::setRotation(float newRotation) {
    if (transform) {
        sprite.setRotation(newRotation);
        transform->setTransformRotation(newRotation);
    }
}

void Sprite::setScale() {
    if (transform) {
        sprite.setScale(transform->getTransformStruct().scale.getX(), transform->getTransformStruct().scale.getY());
    }
}

void Sprite::setScale(Vector2<float> newScale) {
    if (transform) {
        sprite.setScale(newScale.getX(), newScale.getY());
        transform->setTransformScale(newScale);
    }
}

Rect<float> Sprite::getBounds() const {
    sf::FloatRect bounds = sprite.getGlobalBounds();
    return Rect<float>(bounds.left, bounds.top, bounds.width, bounds.height);
<<<<<<< HEAD
}

void Sprite::setTransform(Transform& newTransform) {
    transform = &newTransform;
=======
>>>>>>> ef4437f ([m] Engine:)
}