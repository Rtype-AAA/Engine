//
// Created by thibaultcampagne on 29/11/23.
//

#include "World/world.h"


int main() {
    Entity player("Louis");
    World test(sf::VideoMode(1920, 1080), "2d", "SFML Window");
    std::map<std::string, std::vector<float>> mapTransform;
    mapTransform["Position"] = {1.0f, 5.0f};
    mapTransform["Rotation"] = {4.0f, 21.3f};
    mapTransform["Scale"] = {0.0f, 0.0f};

    std::map<std::string, std::pair<std::unique_ptr<EntityManager>, std::vector<std::string>>> mapEntityManager;
    mapEntityManager["players"] = std::make_pair(std::make_unique<EntityManager>(), std::vector<std::string>{"Thibault", "Pierre", "Louis"});

    test.createEntities(mapEntityManager);

    mapEntityManager["players"].first->getEntity<Entity>("Thibault").addComponent<Transform>(mapTransform);
    mapEntityManager["players"].first->getEntity<Entity>("Louis").addComponent<Transform>();

    std::cout << mapEntityManager["players"].first->getEntity<Entity>("Thibault").getComponent<Transform>().getPositionVector()[0] << ", ";
    std::cout << mapEntityManager["players"].first->getEntity<Entity>("Thibault").getComponent<Transform>().getPositionVector()[1] << std::endl;

    std::cout << mapEntityManager["players"].first->getEntity<Entity>("Louis").getComponent<Transform>().getPositionVector()[0] << ", ";
    std::cout << mapEntityManager["players"].first->getEntity<Entity>("Louis").getComponent<Transform>().getPositionVector()[1] << std::endl;
//    players->getEntity<Entity>("Thibault").addComponent<Transform>(mapTransform);
//    std::cout << &players->getEntity<Entity>("Thibault").getComponent<Transform>() << std::endl;
//    std::cout << "Player: " << &player << std::endl;
//    std::cout << "main " << &player.addComponent<Transform>() << std::endl;
//    std::cout << "Name: " << player.getName() << std::endl;
//    player.setName("Louis");
//    std::cout << "Name: " << player.getName() << std::endl;
//    std::cout << &player.getComponent<Transform>() << std::endl;
//    for (const auto& element : mapTransform) {
//        std::cout << element.second[1] << std::endl;
//    }
//    std::cout << "{" << players->getEntity<Entity>("Thibault").getComponent<Transform>().getPositionVector()[0] << ", ";
//    std::cout << players->getEntity<Entity>("Thibault").getComponent<Transform>().getPositionVector()[1] << "}" << std::endl;
//    std::cout << "{" << players->getEntity<Entity>("Thibault").getComponent<Transform>().getRotationVector()[0] << ", ";
//    std::cout << players->getEntity<Entity>("Thibault").getComponent<Transform>().getRotationVector()[1] << "}" << std::endl;
//    std::cout << "{" << players->getEntity<Entity>("Thibault").getComponent<Transform>().getScaleVector()[0] << ", ";
//    std::cout << players->getEntity<Entity>("Thibault").getComponent<Transform>().getScaleVector()[1] << "}" << std::endl;
//    std::cout << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getPositionVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getPositionVector()[1] << "}" << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getRotationVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getRotationVector()[1] << "}" << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getScaleVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getScaleVector()[1] << "}" << std::endl;
//    player.getComponent<Transform>().setTransform(mapTransform);
//    std::cout << "{" << player.getComponent<Transform>().getPositionVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getPositionVector()[1] << "}" << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getRotationVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getRotationVector()[1] << "}" << std::endl;
//    std::cout << "{" << player.getComponent<Transform>().getScaleVector()[0] << ", ";
//    std::cout << player.getComponent<Transform>().getScaleVector()[1] << "}" << std::endl;
    return 0;
}