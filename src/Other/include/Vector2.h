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
    Vector2<T>() : vect{0, 0} {}

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
    [[nodiscard]] Vector2Struct getVector2Struct() const;

    /// @brief getX(): Get x of Vector2Struct.
    /// @tparam: T: Type of the Vector2
    /// @param void
    /// @return T: Depends of the Vector2
    [[nodiscard]] T getX() const;

    /// @brief getY(): Get y of Vector2Struct.
    /// @tparam: T: Type of the Vector2
    /// @param void
    /// @return T: Depends of the Vector2
    [[nodiscard]] T getY() const;

    /**
     * @brief setX(): Set x of Vector2Struct.
     * @tparam T: Type of the Vector2
     * @param newX: The new value of x.
     */
    void setX(T newX);

    /**
     * @brief setY(): Set y of Vector2Struct.
     * @tparam T: Type of the Vector2
     * @param newY: The new value of y.
     */
    void setY(T newY);
};

extern template Vector2<float>::Vector2Struct Vector2<float>::getVector2Struct() const;
extern template float Vector2<float>::getY() const;
extern template float Vector2<float>::getX() const;
extern template void Vector2<float>::setY(float newY);
extern template void Vector2<float>::setX(float newX);

extern template Vector2<int>::Vector2Struct Vector2<int>::getVector2Struct() const;
extern template int Vector2<int>::getY() const;
extern template int Vector2<int>::getX() const;
extern template void Vector2<int>::setY(int newY);
extern template void Vector2<int>::setX(int newX);