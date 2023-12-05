//
// Created by thibaultcampagne on 29/11/23.
//

#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <array>
#include "../Components/Components.h"
#include "../Archetype/Archetypes.h"

class Entity : private Components {
private:
    std::string name{};
    std::vector<std::unique_ptr<Components>> components{};
    Components::ComponentBitset componentBitset;
    Components::ComponentArray componentArray{};
public:
    Entity() = default;
    explicit Entity(std::string nameEntity, Archetypes newArchetype = Archetypes()) {
        name = std::move(nameEntity);
    }
    ~Entity() override = default;

    [[nodiscard]] std::string getName() const;
    void setName(std::string newName);

    template<typename T, typename... TArgs>
    T& addComponent(TArgs&&... args);

    template<typename T>
    T& getComponent();
};

#include "entity.cpp"

#endif //ENGINE_ENTITY_H
