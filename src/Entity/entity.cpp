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

bool Entity::init() {
    for (int i = 0; i < componentBitset.size(); i++) {
        componentBitset[i] = false;
    }
    return true;
}

void Entity::addDrawable(Components *component) {
    DrawableComponent *newDrawableComponent = dynamic_cast<DrawableComponent*>(component);
    if (newDrawableComponent) {
        drawableComponents.emplace_back(newDrawableComponent);
    }
}

void Entity::draw(sf::RenderWindow& window) {
    for (const auto& component: drawableComponents) {
        component->draw(window);
    }
}

template<typename T, typename... TArgs>
T& Entity::addComponent(TArgs&&... args) {
    std::unique_ptr<T> newComponent = std::make_unique<T>(std::forward<TArgs>(args)...);
    if (!newComponent->init()) {
        throw std::runtime_error("Echec de l'initialisation de Component");
    }
    T* comp = newComponent.get();
    addDrawable(comp);
    components.emplace_back(std::move(newComponent));
    componentArray[comp->getBit()] = comp;
    componentBitset[comp->getBit()] = true;
    return *comp;
}

template<typename T>
T& Entity::getComponent() {
    auto ptr = componentArray[Components::getComponentTypeID<T>()];
    return *static_cast<T*>(ptr);
}