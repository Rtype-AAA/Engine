//
// Created by thibaultcampagne on 29/11/23.
//

#include "Entity/entity.h"
#include <iostream>
#include "include/all_components.h"


int main() {
    Entity player("Thibault");

    std::cout << "Player: " << &player << std::endl;
    player.addComponent<Transform>();
    std::cout << "Name: " << player.getName() << std::endl;
    player.setName("Louis");
    std::cout << "Name: " << player.getName() << std::endl;

    return 0;
}