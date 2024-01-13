//
// Created by thibaultcampagne on 10/01/24.
//

#include "Rect.h"

template<typename T>
typename Rect<T>::RectStruct  Rect<T>::getRect() const {
    return rect;
}

template<typename T>
T Rect<T>::getLeft() const {
    return rect.left;
}

template<typename T>
T Rect<T>::getTop() const {
    return rect.top;
}

template<typename T>
T Rect<T>::getWidth() const {
    return rect.width;
}

template<typename T>
T Rect<T>::getHeight() const {
    return rect.height;
}

template<typename T>
bool Rect<T>::contains(T x, T y) const {
    if (x >= rect.left && x <= rect.left + rect.width && y >= rect.top && y <= rect.top + rect.width) {
        return true;
    } else {
        return false;
    }
}

template float Rect<float>::getLeft() const;
template float Rect<float>::getTop() const;
template float Rect<float>::getWidth() const;
template float Rect<float>::getHeight() const;
template bool Rect<float>::contains(float x, float y) const;

template int Rect<int>::getLeft() const;
template int Rect<int>::getTop() const;
template int Rect<int>::getWidth() const;
template int Rect<int>::getHeight() const;
template bool Rect<int>::contains(int x, int y) const;
