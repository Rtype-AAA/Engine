//
// Created by thibaultcampagne on 29/11/23.
//

#include "Components.h"

//inline Components::ComponentTypeID Components::getUniqueComponentID() {
//    static ComponentTypeID lastID = 0u;
//    return lastID++;
//}

template<typename T>
inline Components::ComponentTypeID Components::getComponentTypeID() noexcept {
    static_assert(std::is_base_of<Components,T>::value, "Type not base on components!");
    static const ComponentTypeID typeID = getUniqueComponentID();
    return typeID;
}