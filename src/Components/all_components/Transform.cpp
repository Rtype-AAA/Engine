//
// Created by thibaultcampagne on 30/11/23.
//

#include "Transform.h"

bool Transform::init() {
    return true;
}

void Transform::update(sf::Time deltaTime) {
    applyDeferredTransform();
}

int Transform::getBit() {
    return bit;
}

Vector2<float> Transform::getPosition() const {
    return transform.position;
}

float Transform::getRotation() const {
    return transform.rotation;
}

Vector2<float> Transform::getScale() const {
    return transform.scale;
}

Transform::TransformStruct Transform::getTransform() const {
    return transform;
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

void Transform::setDeferredTransform(const std::function<void()>& setter) {
    deferredTransform = setter;
}

void Transform::applyDeferredTransform() {
    if (deferredTransform) {
        deferredTransform();
    }
}
