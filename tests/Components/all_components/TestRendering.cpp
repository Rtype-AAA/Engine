#include <gtest/gtest.h>
#include "../../../include/all_components.h"

class RenderingTest : public ::testing::Test {
protected:
    Rendering rendering;
};

TEST_F(RenderingTest, DefaultConstructor) {
    Rendering render;

    ASSERT_EQ(render.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, ConstructorWithTexturePath) {
    Rendering render("assets/red.png");

    ASSERT_NE(render.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, CreateSpriteWithTexturePath) {
    ASSERT_TRUE(rendering.createSprite("assets/red.png"));
    ASSERT_NE(rendering.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, CreateSpriteWithExistingTexture) {
    sf::Texture texture;

    ASSERT_TRUE(rendering.createSprite(texture));
    ASSERT_NE(rendering.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, CreateSpriteWithTheComponentTexture) {
    Rendering render("assets/red.png");

    ASSERT_TRUE(render.createSprite());
    ASSERT_NE(render.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, SetSpriteWithAnExistingSprite) {
    Rendering render("assets/red.png");

    sf::Texture texture;
    texture.loadFromFile("assets/blue.png");

    sf::Sprite newSprite;
    newSprite.setTexture(texture);

    ASSERT_NE(render.getSprite().getTexture(), newSprite.getTexture());

    ASSERT_TRUE(render.setSprite(newSprite));
    ASSERT_NE(render.getSprite().getTexture(), nullptr);
    ASSERT_EQ(render.getSprite().getTexture(), newSprite.getTexture());
}

TEST_F(RenderingTest, SetTextureWithTexturePath) {
    Rendering render("assets/red.png");

    sf::Texture newTexture;
    newTexture.loadFromFile("assets/blue.png");

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(render.getSprite().getTexture(), newSprite.getTexture());

    ASSERT_TRUE(render.setTexture(newTexture));
    ASSERT_NE(render.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, SetTextureWithAnExistingTexture) {
    Rendering render("assets/red.png");

    sf::Texture newTexture;
    newTexture.loadFromFile("assets/blue.png");

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(render.getSprite().getTexture(), newSprite.getTexture());

    ASSERT_TRUE(rendering.setTexture(newTexture));
    ASSERT_NE(rendering.getSprite().getTexture(), nullptr);
}