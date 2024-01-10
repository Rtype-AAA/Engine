//
// Created by thibaultcampagne on 10/01/24.
//

#pragma once

template <typename T>
class Vector2 {
private:
    struct Position {
        T x;
        T y;
    };
    Position pos;
public:
    Vector2<T>(T x, T y) : pos{x, y} {};

    ~Vector2<T>() = default;

    Position getPosition() const {return pos;}

    T getX() const {return pos.x;}
    T getY() const {return pos.y;}
};
