//
// Created by thibaultcampagne on 29/11/23.
//

#include "entity.h"

void Entity::setDeferredEntity(std::function<void()> setter) {
    deferredEntity = std::move(setter);
}

void Entity::applyDeferredEntity() {
    if (deferredEntity) {
        deferredEntity();
    }
}

Entity::Entity(const std::string& nameEntity, Archetypes newArchetype) : active(true) {
    name = nameEntity;
}

bool Entity::init() {
    for (int i = 0; i < componentBitset.size(); i++) {
        componentBitset[i] = false;
    }
    return true;
}

std::string Entity::getName() const {
    return name;
}

void Entity::update(sf::Time deltaTime) {
    for (size_t i = 0; i < componentBitset.size(); i++) {
        if (componentBitset.test(i)) {
            componentArray[i]->update(deltaTime);
        }
    }
}

void Entity::setName(std::string newName) {
    name = std::move(newName);
}

void Entity::addDrawable(Components *component) {
    auto *newDrawableComponent = dynamic_cast<DrawableComponent*>(component);
    if (newDrawableComponent) {
        drawableComponents.emplace_back(newDrawableComponent);
    }
}

void Entity::removeDrawable(Components *component) {
    auto *newDrawableComponent = dynamic_cast<DrawableComponent*>(component);
    if (newDrawableComponent) {
        for (auto it = drawableComponents.begin(); it != drawableComponents.end(); it++) {
            if (*it == newDrawableComponent) {
                drawableComponents.erase(it);
                break;
            }
        }
    }
}

void Entity::drawEntity(sf::RenderWindow& window) {
    for (const auto &component: drawableComponents) {
        component->draw(window);
    }
}

template<typename T, typename... TArgs>
T& Entity::addComponent(TArgs&&... args) {
    std::unique_ptr<T> newComponent = std::make_unique<T>(std::forward<TArgs>(args)...);
    if constexpr(std::is_same_v<T, Sprite> || std::is_same_v<T, Text>) {
        if (this->getComponentBitset().test(0)) {
            newComponent->setTransform(this->getComponent<Transform>());
        }
    }
    if (!newComponent->init()) {
        throw std::runtime_error("Failure to initialize Component");
    }
    T* comp = newComponent.get();
    addDrawable(comp);
    components.emplace_back(std::move(newComponent));
    componentArray[comp->getBit()] = comp;
    componentBitset[comp->getBit()] = true;
    return *comp;
}

template<typename T>
bool Entity::removeComponent() {
    int bit = getComponentTypeID<T>();

    if (this->getComponentBitset().test(bit)) {
        for (auto it = components.begin(); it != components.end(); it++) {
            if ((*it)->getBit() == bit) {
                removeDrawable((*it).get());
                componentBitset[bit] = false;
                componentArray[bit] = nullptr;
                components.erase(it);
                return true;
            }
        }
    }
    return false;
}

template<typename T>
T& Entity::getComponent() {
    auto ptr = componentArray[getComponentTypeID<T>()];
    if (ptr == nullptr) {
        throw std::runtime_error("The component don't exist, probably removed or not added");
    }

    T* castedPtr = dynamic_cast<T*>(ptr);
    if (castedPtr == nullptr) {
        throw std::runtime_error("Component type mismatch");
    }
    return *castedPtr;
}

template<typename T>
std::size_t Entity::getComponentTypeID() noexcept {
    static const std::size_t typeID = std::make_unique<T>()->getBit();
    return typeID;
}

std::bitset<6> Entity::getComponentBitset() const {
    return componentBitset;
}

std::vector<DrawableComponent*> Entity::getDrawableComponents() const {
    return drawableComponents;
}

std::array<Components*, 6> Entity::getComponentArrays() const {
    return componentArray;
}

int Entity::getBit() {
    return 0;
}

void Entity::setActive(bool isActive) {
    if (isActive) {
        active = true;
    } else {
        active = false;
    }
}

bool Entity::getActive() const {
    return active;
}

template Transform& Entity::addComponent<Transform>();
template bool Entity::removeComponent<Transform>();
template Transform& Entity::getComponent<Transform>();
template std::size_t Entity::getComponentTypeID<Transform>();

template Sprite& Entity::addComponent<Sprite>();
template bool Entity::removeComponent<Sprite>();
template Sprite& Entity::getComponent<Sprite>();
template std::size_t Entity::getComponentTypeID<Sprite>();

template Music& Entity::addComponent<Music>();
template bool Entity::removeComponent<Music>();
template Music& Entity::getComponent<Music>();
template std::size_t Entity::getComponentTypeID<Music>();

template Sound& Entity::addComponent<Sound>();
template bool Entity::removeComponent<Sound>();
template Sound& Entity::getComponent<Sound>();
template std::size_t Entity::getComponentTypeID<Sound>();

template Text& Entity::addComponent<Text>();
template bool Entity::removeComponent<Text>();
template Text& Entity::getComponent<Text>();
template std::size_t Entity::getComponentTypeID<Text>();
