//
// Created by thibaultcampagne on 10/01/24.
//

#include "Vector2.h"


template<typename T>
typename Vector2<T>::Vector2Struct Vector2<T>::getVector2Struct() const {
    return vect;
}

template<typename T>
T Vector2<T>::getX() const {
    return vect.x;
}

template<typename T>
T Vector2<T>::getY() const {
    return vect.y;
}

template<typename T>
void Vector2<T>::setX(T newX) {
    vect.x =  newX;
}

template<typename T>
void Vector2<T>::setY(T newY) {
    vect.y = newY;
}

template Vector2<float>::Vector2Struct Vector2<float>::getVector2Struct() const;
template float Vector2<float>::getY() const;
template float Vector2<float>::getX() const;
template void Vector2<float>::setY(float newY);
template void Vector2<float>::setX(float newX);

template Vector2<int>::Vector2Struct Vector2<int>::getVector2Struct() const;
template int Vector2<int>::getY() const;
template int Vector2<int>::getX() const;
template void Vector2<int>::setY(int newY);
template void Vector2<int>::setX(int newX);