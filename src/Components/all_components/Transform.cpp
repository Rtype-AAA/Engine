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

<<<<<<< HEAD
<<<<<<< HEAD
void Transform::setTransformPosition(Vector2<float> newPosition) {
    transform.position = newPosition;
}

void Transform::setTransformRotation(float newRotation) {
    transform.rotation = newRotation;
}

void Transform::setTransformScale(Vector2<float> newScale) {
=======
void Transform::setPosition(Vector2<float> newPosition) {
=======
void Transform::setTransformPosition(Vector2<float> newPosition) {
>>>>>>> b57d10d ([m] Engine:)
    transform.position = newPosition;
}

void Transform::setTransformRotation(float newRotation) {
    transform.rotation = newRotation;
}

<<<<<<< HEAD
void Transform::setScale(Vector2<float> newScale) {
>>>>>>> 8bf355f ([m] Engine:)
=======
void Transform::setTransformScale(Vector2<float> newScale) {
>>>>>>> b57d10d ([m] Engine:)
    transform.scale = newScale;
}
