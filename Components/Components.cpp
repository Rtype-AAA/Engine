//
// Created by thibaultcampagne on 29/11/23.
//

#include "Components.h"

//inline Components::ComponentTypeID Components::getUniqueComponentID() {
//    static ComponentTypeID lastID = 0u;
//    return lastID++;
//}

template<typename T>
Components::ComponentTypeID Components::getComponentTypeID() noexcept {
    static_assert(std::is_base_of<Components,T>::value, "Type not base on components!");
    T* comp = new T();
    static const ComponentTypeID typeID = comp->getBit();
    return typeID;
}
