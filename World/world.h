//
// Created by thibaultcampagne on 20/12/23.
//

#ifndef R_TYPE_WORLD_H
#define R_TYPE_WORLD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "../Entity/entity.h"

class World : private Entity{
private:

public:
    World() = default;

    explicit World(std::string type, sf::VideoMode mode, const std::string &title, sf::Uint32 style=sf::Style::Default,
                   const sf::ContextSettings &settings=sf::ContextSettings());

    ~World() = default;

    void createEntities(std::vector<Entity> entities, std::map<std::string, std::vector<std::string>>);
};


#endif //R_TYPE_WORLD_H
