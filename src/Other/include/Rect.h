//
// Created by thibaultcampagne on 10/01/24.
//

#pragma once

#include "Transform.h"

/**
 * @brief Rect class: Rect is a class that represents a rectangle.
 *
 * This create a rectangle and using for what you want.
 */
template<typename T>
class Rect : public Transform {
private:
    struct RectStruct {
        T left;
        T top;
        T width;
        T height;
    }; /// < RectStruct is the struct of Rect.

    RectStruct rect; /// < Rect is the variable you can use for change the data in RectStruct.
public:
    /// @brief Rect constructor with parameters.
    /// @tparam T: Type of the rect.
    /// @param left: Position x.
    /// @param top: Position y.
    /// @param width: Width of your rectangle.
    /// @param height: Height of your rectangle.
    /// @return void
    Rect<T>(T left, T top, T width, T height) : rect{left, top, width, height} {}

    /// @brief Rect destructor.
    /// @tparam T: Type of the rect.
    /// @param void
    /// @return void
    ~Rect<T>() = default;

    /// @brief getRect(): Get the using RectStruct.
    /// @param void
    /// @return Rect
    RectStruct getRect() const {return rect;}

    /// @brief getLeft(): Get the using RectStruct left.
    /// @tparam T: Type of the rect.
    /// @param void
    /// @return T : T is the type you want (float, int,...).
    T getLeft() const {return rect.left;}

    /// @brief getTop(): Get the using RectStruct top.
    /// @tparam T: Type of the rect.
    /// @param void
    /// @return T : T is the type you want (float, int,...).
    T getTop() const {return rect.top;}

    /// @brief getWidth(): Get the using RectStruct width.
    /// @tparam T: Type of the rect.
    /// @param void
    /// @return T : T is the type you want (float, int,...).
    T getWidth() const {return rect.width;}

    /// @brief getHeight(): Get the using RectStruct height.
    /// @tparam T: Type of the rect.
    /// @param void
    /// @return T : T is the type you want (float, int,...).
    T getHeight() const {return rect.height;}

    /// @brief contains(): Check if a point is in the rectangle.
    /// @tparam T: Type of the rect.
    /// @param x : Position x of the point.
    /// @param y : Position y of the point.
    /// @return T : T is the type you want (float, int,...).
    bool contains(T x, T y) const;
};

extern template bool Rect<float>::contains(float x, float y) const;
