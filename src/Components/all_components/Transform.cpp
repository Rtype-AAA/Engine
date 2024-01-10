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

std::vector<float> Transform::getPositionVector() const {
    return position;
}

std::vector<float> Transform::getRotationVector() const {
    return rotation;
}

std::vector<float> Transform::getScaleVector() const {
    return scale;
}

void Transform::setTransform(const std::map<std::string, std::vector<float>>& mapTransform) {
    for(const auto& element : mapTransform) {
        if ((element.first == "Position" || element.first == "position") && element.second.size() == 2) {
            position = element.second;
        }
        if ((element.first == "Rotation" || element.first == "rotation") && element.second.size() == 2) {
            rotation = element.second;
        }
        if ((element.first == "Scale" || element.first == "scale") && element.second.size() == 2) {
            scale = element.second;
        }
    }
}
