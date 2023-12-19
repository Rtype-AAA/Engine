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
    Rendering render("tests/assets/red.png");

    ASSERT_NE(render.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, CreateSpriteWithTexturePath) {
    ASSERT_TRUE(rendering.createSprite("tests/assets/red.png"));
    ASSERT_NE(rendering.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, CreateSpriteWithExistingTexture) {
    sf::Texture texture;

    ASSERT_TRUE(rendering.createSprite(texture));
    ASSERT_NE(rendering.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, CreateSpriteWithTheComponentTexture) {
    Rendering render("tests/assets/red.png");

    ASSERT_TRUE(render.createSprite());
    ASSERT_NE(render.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, GetSprite) {
    Rendering render;

    ASSERT_EQ(render.getSprite().getTexture(), nullptr);

    sf::Texture texture;
    texture.loadFromFile("tests/assets/red.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);

    ASSERT_EQ(render.getSprite().getTexture(), nullptr);

    ASSERT_TRUE(render.setSprite(sprite));

    ASSERT_NE(render.getSprite().getTexture(), nullptr);
    ASSERT_EQ(render.getSprite().getTexture(), sprite.getTexture());
}

TEST_F(RenderingTest, GetTexture) {
    const std::string texturePath = "tests/assets/blue.png";

    ASSERT_TRUE(rendering.createSprite(texturePath));

    sf::Texture originalTexture;
    ASSERT_TRUE(originalTexture.loadFromFile(texturePath));

    EXPECT_EQ(rendering.getTexture().getSize(), originalTexture.getSize());
}


TEST_F(RenderingTest, SetSpriteWithAnExistingSprite) {
    Rendering render("tests/assets/red.png");

    sf::Texture newTexture;
    ASSERT_TRUE(newTexture.loadFromFile("tests/assets/blue.png"));

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(render.getSprite().getTexture(), newSprite.getTexture());

    ASSERT_TRUE(render.setSprite(newSprite));
    ASSERT_NE(render.getSprite().getTexture(), nullptr);
    ASSERT_EQ(render.getSprite().getTexture(), newSprite.getTexture());
}

TEST_F(RenderingTest, SetTextureWithTexturePath) {
    Rendering render("tests/assets/red.png");

    sf::Texture newTexture;
    ASSERT_TRUE(newTexture.loadFromFile("tests/assets/blue.png"));

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(render.getSprite().getTexture(), newSprite.getTexture());

    ASSERT_TRUE(render.setTexture(newTexture));
    ASSERT_NE(render.getSprite().getTexture(), nullptr);
}

TEST_F(RenderingTest, SetTextureWithAnExistingTexture) {
    Rendering render("tests/assets/red.png");

    sf::Texture newTexture;
    ASSERT_TRUE(newTexture.loadFromFile("tests/assets/blue.png"));

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(render.getSprite().getTexture(), newSprite.getTexture());

    ASSERT_TRUE(rendering.setTexture(newTexture));
    ASSERT_NE(rendering.getSprite().getTexture(), nullptr);
}