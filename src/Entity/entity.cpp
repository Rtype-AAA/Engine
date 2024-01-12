//
// Created by thibaultcampagne on 29/11/23.
//

#include "entity.h"

std::string Entity::getName() const {
    return name;
}

void Entity::setName(std::string newName) {
    name = std::move(newName);
}

void Entity::update(sf::Time deltaTime) {
    for (size_t i = 0; i < componentBitset.size(); i++) {
        if (componentBitset.test(i)) {
            componentArray[i]->update(deltaTime);
        }
    }
}

bool Entity::initEntity() {
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

void Entity::drawEntity(sf::RenderWindow& window) {
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
    if constexpr (std::is_same_v<T, Sprite>) {
        if (this->getComponentBitset().test(0)) {
            newComponent->setTransform(this->getComponent<Transform>());
        }
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
    auto ptr = componentArray[getComponentTypeID<T>()];
    return *static_cast<T*>(ptr);
}

template<typename T>
std::size_t Entity::getComponentTypeID() noexcept {
    std::unique_ptr<T> comp = std::make_unique<T>();
    static const std::size_t typeID = comp->getBit();
    return typeID;
}

template std::size_t Entity::getComponentTypeID<Transform>();
template Transform& Entity::addComponent<Transform>();
template Transform& Entity::getComponent<Transform>();

template Sprite& Entity::addComponent<Sprite>();
template std::size_t Entity::getComponentTypeID<Sprite>();
template Sprite& Entity::addComponent<Sprite>(std::string&);
template Sprite& Entity::getComponent<Sprite>();

template Music& Entity::addComponent<Music>();
template std::size_t Entity::getComponentTypeID<Music>();
template Music& Entity::getComponent<Music>();

template Sound& Entity::addComponent<Sound>();
template std::size_t Entity::getComponentTypeID<Sound>();
template Sound& Entity::getComponent<Sound>();
