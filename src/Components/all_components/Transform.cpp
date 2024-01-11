//
// Created by thibaultcampagne on 30/11/23.
//

#include "Transform.h"

int Transform::getBit() const {
    return bit;
}

void Transform::update(sf::Time deltaTime) {
    return;
}

void Transform::setTransform(Vector2<float> newPosition, float newRotation, Vector2<float> newScale) {
    transform.position = newPosition;
    transform.rotation = newRotation;
    transform.scale = newScale;
}

void Transform::setPosition(Vector2<float> newPosition) {
    transform.position = newPosition;
}

void Transform::setRotation(float newRotation) {
    transform.rotation = newRotation;
}

void Transform::setScale(Vector2<float> newScale) {
    transform.scale = newScale;
}
