//
// Created by thibaultcampagne on 29/11/23.
//

#ifndef ENGINE_COMPONENTS_H
#define ENGINE_COMPONENTS_H

#include <iostream>
#include <bitset>

class Components {
protected:
    using ComponentTypeID = std::size_t;
    using ComponentBitset = std::bitset<3>;
    using ComponentArray = std::array<Components*, 3>;
public:
    Components() = default;
    virtual ~Components() = default;

    virtual bool init() {return true;}
    virtual void draw() {}
    virtual void update() {}

//    static inline ComponentTypeID getUniqueComponentID();
//
    template<typename T>
    ComponentTypeID getComponentTypeID() noexcept;
};

#include "Components.cpp"

#endif //ENGINE_COMPONENTS_H
