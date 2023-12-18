//
// Created by thibaultcampagne on 29/11/23.
//

#include "Entity/entity.h"
#include <iostream>
#include "include/all_components.h"


int main() {
    Entity player("Thibault");
    std::map<std::string, std::vector<float>> mapTransform;

    mapTransform["Position"] = {1.0f, 5.0f};
    mapTransform["Rotation"] = {4.0f, 21.3f};
    mapTransform["Scale"] = {0.0f, 0.0f};
    std::cout << "Player: " << &player << std::endl;
    std::cout << "main " << &player.addComponent<Transform>() << std::endl;
    std::cout << "Name: " << player.getName() << std::endl;
    player.setName("Louis");
    std::cout << "Name: " << player.getName() << std::endl;
    std::cout << &player.getComponent<Transform>() << std::endl;
    for (const auto& element : mapTransform) {
        std::cout << element.second[1] << std::endl;
    }
    std::cout << "{" << player.getComponent<Transform>().getPositionVector()[0] << ", ";
    std::cout << player.getComponent<Transform>().getPositionVector()[1] << "}" << std::endl;
    std::cout << "{" << player.getComponent<Transform>().getRotationVector()[0] << ", ";
    std::cout << player.getComponent<Transform>().getRotationVector()[1] << "}" << std::endl;
    std::cout << "{" << player.getComponent<Transform>().getScaleVector()[0] << ", ";
    std::cout << player.getComponent<Transform>().getScaleVector()[1] << "}" << std::endl;
    player.getComponent<Transform>().setTransform(mapTransform);
    std::cout << "{" << player.getComponent<Transform>().getPositionVector()[0] << ", ";
    std::cout << player.getComponent<Transform>().getPositionVector()[1] << "}" << std::endl;
    std::cout << "{" << player.getComponent<Transform>().getRotationVector()[0] << ", ";
    std::cout << player.getComponent<Transform>().getRotationVector()[1] << "}" << std::endl;
    std::cout << "{" << player.getComponent<Transform>().getScaleVector()[0] << ", ";
    std::cout << player.getComponent<Transform>().getScaleVector()[1] << "}" << std::endl;

    return 0;
}