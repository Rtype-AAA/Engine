//
// Created by thibaultcampagne on 20/12/23.
//

#ifndef R_TYPE_WORLD_H
#define R_TYPE_WORLD_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include "../Entity/entityManager.h"
#include "../include/all_components.h"

class World: protected EntityManager {
protected:
    using EntityManagerMap = std::map<std::string, EntityManager*>;
private:
    std::map<std::string, std::unique_ptr<EntityManager>> entitiesManager{};
    EntityManagerMap entityManagerMap{};
public:
    World() = default;

    ~World() override = default;

    void createEntities(std::map<std::string, std::pair<std::unique_ptr<EntityManager>,
            std::vector<std::string>>>& mapEntityManager, std::string keyEntityManager);

    EntityManager& addEntityManager(std::string NameEntityManager);
    EntityManager& getEntityManager(std::string NameEntityManager);
};


#endif //R_TYPE_WORLD_H
