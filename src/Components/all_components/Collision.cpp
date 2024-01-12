#include "Collision.h"


bool Collision::initCollision() {
    // Initialization logic for Collision (if needed)
    return true; // Return true if initialized successfully
}


bool Collision::checkCollision(const std::vector<Sprite>& sprites) {
    // Iterate through all pairs of sprites and check for collisions
    for (size_t i = 0; i < sprites.size(); ++i) {
        for (size_t j = i + 1; j < sprites.size(); ++j) {
            sf::FloatRect rect1 = sprites[i].getSprite().getGlobalBounds();
            sf::FloatRect rect2 = sprites[j].getSprite().getGlobalBounds();

            if (rect1.intersects(rect2)) {
                return true;
            }
        }
    }

    return false;
}
