//
// Created by thibaultcampagne on 29/11/23.
//

#include "entity.h"
#include <utility>

std::string Entity::getName() const {
    return name;
}

void Entity::setName(std::string newName) {
    name = std::move(newName);
}

template<typename T, typename... TArgs>
T& Entity::addComponent(TArgs&&... args) {
    T* comp = new T(std::forward<TArgs>(args)...);
    std::unique_ptr<Components> uptr {comp};
    components.emplace_back(std::move(uptr));
    if (comp->init()) {
        componentArray[comp->getBit()] = comp;
        componentBitset[comp->getBit()] = true;
        return *comp;
    }
    return *static_cast<T*>(nullptr);
}

template<typename T>
T& Entity::getComponent() {
    auto ptr = componentArray[Components::getComponentTypeID<T>()];
    return *static_cast<T*>(ptr);
}