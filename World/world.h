//
// Created by thibaultcampagne on 20/12/23.
//

#ifndef R_TYPE_WORLD_H
#define R_TYPE_WORLD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include "../Entity/entityManager.h"

class World : private EntityManager{
private:

public:
    World() = default;

    explicit World(std::string type, sf::VideoMode mode, const std::string &title, sf::Uint32 style=sf::Style::Default,
                   const sf::ContextSettings &settings=sf::ContextSettings());

    ~World() = default;

    void createEntities(std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager);
};


#endif //R_TYPE_WORLD_H
