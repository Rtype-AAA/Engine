//
// Created by thibaultcampagne on 10/01/24.
//

#include "Rect.h"

template<typename T>
bool Rect<T>::contains(T x, T y) const {
    if (x >= rect.left && x <= rect.left + rect.width && y >= rect.top && y <= rect.top + rect.width) {
        return true;
    } else {
        return false;
    }
}

template bool Rect<float>::contains(float x, float y) const;