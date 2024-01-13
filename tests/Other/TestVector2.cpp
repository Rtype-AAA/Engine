#include "Vector2.h"
#include "gtest/gtest.h"

class TestVector2 : public ::testing::Test {
protected:
    Vector2<float> vector2 = Vector2<float>(0, 0);
};

TEST_F(TestVector2, TestVector2Constructor) {
    ASSERT_EQ(vector2.getVector2Struct().x, 0);
    ASSERT_EQ(vector2.getVector2Struct().y, 0);

    vector2 = Vector2<float>(1, 1);
    ASSERT_EQ(vector2.getVector2Struct().x, 1);
    ASSERT_EQ(vector2.getVector2Struct().y, 1);
}

TEST_F(TestVector2, TestVector2GetVector2Struct) {
    ASSERT_EQ(vector2.getVector2Struct().x, vector2.getX());
    ASSERT_EQ(vector2.getVector2Struct().y, vector2.getY());

    vector2 = Vector2<float>(1, 1);
    ASSERT_EQ(vector2.getVector2Struct().x, vector2.getX());
    ASSERT_EQ(vector2.getVector2Struct().y, vector2.getY());
}

TEST_F(TestVector2, TestVector2GetX) {
    ASSERT_EQ(vector2.getX(), 0);

    vector2 = Vector2<float>(1, 0);
    ASSERT_EQ(vector2.getX(), 1);
}

TEST_F(TestVector2, TestVector2GetY) {
    ASSERT_EQ(vector2.getY(), 0);

    vector2 = Vector2<float>(0, 1);
    ASSERT_EQ(vector2.getY(), 1);
}
