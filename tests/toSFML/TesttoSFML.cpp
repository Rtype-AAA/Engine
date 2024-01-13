#include "toSFML.h"
#include "gtest/gtest.h"

class TesttoSFML : public ::testing::Test {
protected:
    toSFML toSFML1 = toSFML();
};

TEST_F(TesttoSFML, TesttoSFMLConstructor) {
    ASSERT_EQ(toSFML1.toSFMLRect(Rect<int>(0, 0, 0, 0)), sf::Rect<int>(0, 0, 0, 0));
    ASSERT_EQ(toSFML1.toSFMLRect(Rect<float>(0, 0, 0, 0)), sf::Rect<float>(0, 0, 0, 0));
}

TEST_F(TesttoSFML, TesttoSFMLtoSFMLRect) {
    ASSERT_EQ(toSFML1.toSFMLRect(Rect<int>(1, 2, 3, 4)), sf::Rect<int>(1, 2, 3, 4));
    ASSERT_EQ(toSFML1.toSFMLRect(Rect<float>(1, 2, 3, 4)), sf::Rect<float>(1, 2, 3, 4));
}
