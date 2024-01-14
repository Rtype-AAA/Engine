#include "Color.h"
#include "gtest/gtest.h"

class TestColor : public ::testing::Test {
protected:
    Color color;

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(TestColor, DefaultConstructor) {
    EXPECT_EQ(255, color.getRed());
    EXPECT_EQ(255, color.getGreen());
    EXPECT_EQ(255, color.getBlue());
    EXPECT_EQ(255, color.getAlpha());
}

TEST_F(TestColor, GetRed) {
    EXPECT_EQ(255, color.getRed());

    color.setRed(0);

    EXPECT_EQ(0, color.getRed());
}

TEST_F(TestColor, GetGreen) {
    EXPECT_EQ(255, color.getGreen());

    color.setGreen(0);

    EXPECT_EQ(0, color.getGreen());
}

TEST_F(TestColor, GetBlue) {
    EXPECT_EQ(255, color.getBlue());

    color.setBlue(0);

    EXPECT_EQ(0, color.getBlue());
}

TEST_F(TestColor, GetAlpha) {
    EXPECT_EQ(255, color.getAlpha());

    color.setAlpha(0);

    EXPECT_EQ(0, color.getAlpha());
}

TEST_F(TestColor, SetRed) {
    EXPECT_EQ(255, color.getRed());

    color.setRed(0);

    EXPECT_EQ(0, color.getRed());
}

TEST_F(TestColor, SetGreen) {
    EXPECT_EQ(255, color.getGreen());

    color.setGreen(0);

    EXPECT_EQ(0, color.getGreen());
}

TEST_F(TestColor, SetBlue) {
    EXPECT_EQ(255, color.getBlue());

    color.setBlue(0);

    EXPECT_EQ(0, color.getBlue());
}

TEST_F(TestColor, SetAlpha) {
    EXPECT_EQ(255, color.getAlpha());

    color.setAlpha(0);

    EXPECT_EQ(0, color.getAlpha());
}

TEST_F(TestColor, OperatorSfColor) {
    sf::Color sfColor = static_cast<sf::Color>(color);

    EXPECT_EQ(255, sfColor.r);
    EXPECT_EQ(255, sfColor.g);
    EXPECT_EQ(255, sfColor.b);
    EXPECT_EQ(255, sfColor.a);
}

TEST_F(TestColor, FromSFMLColor) {
    sf::Color sfColor = static_cast<sf::Color>(color);

    Color colorFromSFML = Color::fromSFMLColor(sfColor);

    EXPECT_EQ(255, colorFromSFML.getRed());
    EXPECT_EQ(255, colorFromSFML.getGreen());
    EXPECT_EQ(255, colorFromSFML.getBlue());
    EXPECT_EQ(255, colorFromSFML.getAlpha());
}
