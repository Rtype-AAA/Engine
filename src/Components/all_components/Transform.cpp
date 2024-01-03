//
// Created by thibaultcampagne on 30/11/23.
//

#include "Transform.h"

int Transform::getBit() const {
    return bit;
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
        if ((element.first == "Position" or element.first == "position") and element.second.size() == 2) {
            position = element.second;
        }
        if ((element.first == "Rotation" or element.first == "rotation") and element.second.size() == 2) {
            rotation = element.second;
        }
        if ((element.first == "Scale" or element.first == "scale") and element.second.size() == 2) {
            scale = element.second;
        }
    }
}
