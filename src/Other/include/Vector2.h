//
// Created by thibaultcampagne on 10/01/24.
//

#pragma once

template <typename T>
class Vector2 {
private:
    struct Vector2Struct {
        T x;
        T y;
    };
    Vector2Struct vect;
public:
    Vector2<T>(T x, T y) : vect{x, y} {}

    ~Vector2<T>() = default;

    Vector2Struct getVector2Struct() const {return vect;}

    T getX() const {return vect.x;}
    T getY() const {return vect.y;}
};
