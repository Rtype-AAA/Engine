//
// Created by thibaultcampagne on 10/01/24.
//

#pragma once

template<typename T>
class Rect {
private:
    struct Data {
        T left;
        T top;
        T width;
        T height;
    };

    Data data;
public:
    Rect<T>(T left, T top, T width, T height) : data{left, top, width, height} {}

    ~Rect<T>() = default;

    Data getRect() const {return data;}

    T getLeft() const {return data.left;}
    T getTop() const {return data.top;}
    T getWidth() const {return data.width;}
    T getHeight() const {return data.height;}
};
