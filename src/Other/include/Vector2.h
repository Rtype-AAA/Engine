//
// Created by thibaultcampagne on 10/01/24.
//

#pragma once

/**
 * @brief Vector class: Vector is a class that represents a vector in 2 dimensions.
 *
 * This create a vector with 2 value.
 */
template <typename T>
class Vector2 {
private:
    struct Vector2Struct {
        T x; /// < First value of the vector.
        T y; /// < Second value of the vector.
    };
    Vector2Struct vect; /// < Variable for using the value of the Vector2Struct.
public:
    /// @brief Vector2 constructor with parameters.
    /// @tparam T: Type of the vector.
    /// @param x: Position x.
    /// @param y: Position y.
    /// @return void
    Vector2<T>(T x, T y) : vect{x, y} {}

    /// @brief Vector2 destructor.
    /// @tparam T: Type of the vector.
    /// @param void
    /// @return void
    ~Vector2<T>() = default;

    /// @brief getVector2Struct(): Get the using Vector2Struct.
    /// @param void
    /// @return Vector2Struct
    Vector2Struct getVector2Struct() const {return vect;}

    /// @brief getX(): Get x of Vector2Struct.
    /// @tparam: T: Type of the Vector2
    /// @param void
    /// @return T: Depends of the Vector2
    T getX() const {return vect.x;}

    /// @brief getY(): Get y of Vector2Struct.
    /// @tparam: T: Type of the Vector2
    /// @param void
    /// @return T: Depends of the Vector2
    T getY() const {return vect.y;}
};
