//
// Created by thibaultcampagne on 30/11/23.
//

#include "Transform.h"

int Transform::getBit() const {
    return bit;
}

float Transform::getPositionX() const {
    return position_x;
}

float Transform::getPositionY() const {
    return position_y;
}

float Transform::getRotationX() const {
    return rotation_x;
}

float Transform::getRotationY() const {
    return rotation_y;
}

float Transform::getScaleX() const {
    return scale_x;
}

float Transform::getScaleY() const {
    return scale_y;
}

inline void Transform::setTransform(float px, float py, float rx, float ry, float sx, float sy) {
    position_x = (px != inf) ? px : position_x;
    position_y = (py != inf) ? py : position_y;
    rotation_x = (rx != inf) ? rx : rotation_x;
    rotation_y = (ry != inf) ? ry : rotation_y;
    scale_x = (sx != inf) ? sx : scale_x;
    scale_y = (sy != inf) ? sy : scale_y;
}