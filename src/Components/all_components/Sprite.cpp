//
// Created by thibaultcampagne on 30/11/23.
//

#include "Sprite.h"

void Sprite::doAnimation(sf::Time deltaTime) {
    timeSinceLastFrame += deltaTime;

    if (timeSinceLastFrame >= frameDuration) {
        timeSinceLastFrame -= frameDuration;
        currentFrame = (currentFrame + 1) % frames.size();
        sprite.setTextureRect(toSFMLRect(frames[currentFrame]));
    }
}

Transform* Sprite::getTransform() {
    return transform;
}

bool Sprite::init() {
    if (!transform) {
        return false;
    }
    return true;
}

int Sprite::getBit() {
    return bit;
}

void Sprite::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Sprite::update(sf::Time deltaTime) {
    if (!init()) {
        return;
    }
    if (animation) {
        doAnimation(deltaTime);
    }
    sprite.setPosition(transform->getPosition().getX(), transform->getPosition().getY());
    sprite.setRotation(transform->getRotation());
    sprite.setScale(transform->getScale().getX(), transform->getScale().getY());
}

sf::Sprite Sprite::getSprite() const {
    return sprite;
}

void Sprite::setSprite(const sf::Sprite& newSprite) {
    sprite = newSprite;
}

void Sprite::setSprite(std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture, const std::string& nameTexture,
                       bool animate, const std::vector<Rect<int>>& newFrames, int durationOfFrame) {
    if (!mapTexture.empty()) {
        auto it = mapTexture.find(nameTexture);
        if (it != mapTexture.end()) {
            sprite.setTexture(*(it->second));
            animation = animate;
            if (animate) {
                if (!newFrames.empty()) {
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
    deferredSprite = std::move(setter);
}

void Sprite::setTransform(Transform& newTransform) {
    transform = &newTransform;
}