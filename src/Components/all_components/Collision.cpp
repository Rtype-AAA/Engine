#include "Collision.h"



bool Collision::checkSpriteCollision(Sprite& sprite1, Sprite& sprite2, float push) {
    sf::Sprite& sp1 = sprite1.getSprite();
    sf::Sprite& sp2 = sprite2.getSprite();
    if (AABB(sp1, sp2)) {

        return true;
    return false;
}

void Collision::checkCollisions(std::vector<std::reference_wrapper<Sprite>>& sprites, float push) {
    for (size_t i = 0; i < sprites.size(); ++i) {
        for (size_t j = i + 1; j < sprites.size(); ++j) {
            Sprite& sprite1 = sprites[i];
            Sprite& sprite2 = sprites[j];

            if (checkSpriteCollision(sprite1, sprite2, push)) {

            }
        }
    }
}

bool Collision::AABB(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
    return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
}