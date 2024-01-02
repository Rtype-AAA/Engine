#include <gtest/gtest.h>
#include "../../../include/all_components.h"

class SpriteTest : public ::testing::Test {
protected:
    Sprite sprite;
};

TEST_F(SpriteTest, DefaultConstructor) {
    Sprite sprite;

    ASSERT_EQ(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, ConstructorWithTexturePath) {
    Sprite sprite("src/tests/assets/red.png");

    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, CreateSpriteWithTexturePath) {
    sprite.createSprite("src/tests/assets/red.png");
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, CreateSpriteWithExistingTexture) {
    sf::Texture texture;

    sprite.createSprite(texture);
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, CreateSpriteWithTheComponentTexture) {
    Sprite sprite("src/tests/assets/red.png");

    sprite.createSprite();
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, GetSprite) {
    Sprite sprite;

    ASSERT_EQ(sprite.getSprite().getTexture(), nullptr);

    sf::Texture texture;
    texture.loadFromFile("src/tests/assets/red.png");

    sf::Sprite sfprite;
    sfprite.setTexture(texture);

    ASSERT_EQ(sprite.getSprite().getTexture(), nullptr);

    sprite.setSprite(sfprite);

    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
    ASSERT_EQ(sprite.getSprite().getTexture(), sfprite.getTexture());
}

TEST_F(SpriteTest, GetTexture) {
    const std::string texturePath = "src/tests/assets/blue.png";

    sprite.createSprite(texturePath);

    sf::Texture originalTexture;
    ASSERT_TRUE(originalTexture.loadFromFile(texturePath));

    EXPECT_EQ(sprite.getTexture().getSize(), originalTexture.getSize());
}


TEST_F(SpriteTest, SetSpriteWithAnExistingSprite) {
    Sprite sprite("src/tests/assets/red.png");

    sf::Texture newTexture;
    ASSERT_TRUE(newTexture.loadFromFile("src/tests/assets/blue.png"));

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(sprite.getSprite().getTexture(), newSprite.getTexture());

    sprite.setSprite(newSprite);
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
    ASSERT_EQ(sprite.getSprite().getTexture(), newSprite.getTexture());
}

TEST_F(SpriteTest, SetTextureWithTexturePath) {
    Sprite sprite("src/tests/assets/red.png");

    sf::Texture newTexture;
    ASSERT_TRUE(newTexture.loadFromFile("src/tests/assets/blue.png"));

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(sprite.getSprite().getTexture(), newSprite.getTexture());

    sprite.setTexture(newTexture);
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}

TEST_F(SpriteTest, SetTextureWithAnExistingTexture) {
    Sprite sprite("src/tests/assets/red.png");

    sf::Texture newTexture;
    ASSERT_TRUE(newTexture.loadFromFile("src/tests/assets/blue.png"));

    sf::Sprite newSprite;
    newSprite.setTexture(newTexture);

    ASSERT_NE(sprite.getSprite().getTexture(), newSprite.getTexture());

    sprite.setTexture(newTexture);
    ASSERT_NE(sprite.getSprite().getTexture(), nullptr);
}
