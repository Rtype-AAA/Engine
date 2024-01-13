#include "Rect.h"
#include "gtest/gtest.h"

class TestRect : public ::testing::Test {
protected:
    Rect<float> rect = Rect<float>(0, 0, 0, 0);
};

TEST_F(TestRect, DefaultConstructor) {
    EXPECT_EQ(0, rect.getLeft());
    EXPECT_EQ(0, rect.getTop());
    EXPECT_EQ(0, rect.getWidth());
    EXPECT_EQ(0, rect.getHeight());
}

TEST_F(TestRect, Constructor) {
    Rect<float> rect2(1, 2, 3, 4);

    EXPECT_EQ(1, rect2.getLeft());
    EXPECT_EQ(2, rect2.getTop());
    EXPECT_EQ(3, rect2.getWidth());
    EXPECT_EQ(4, rect2.getHeight());
}

TEST_F(TestRect, GetRect) {
    float left = rect.getRect().left;
    float top = rect.getRect().top;
    float width = rect.getRect().width;
    float height = rect.getRect().height;

    EXPECT_EQ(left, rect.getLeft());
    EXPECT_EQ(top, rect.getTop());
    EXPECT_EQ(width, rect.getWidth());
    EXPECT_EQ(height, rect.getHeight());

    Rect<float> rect2(1, 2, 3, 4);

    left = rect2.getRect().left;
    top = rect2.getRect().top;
    width = rect2.getRect().width;
    height = rect2.getRect().height;

    EXPECT_NE(left, rect.getLeft());
    EXPECT_NE(top, rect.getTop());
    EXPECT_NE(width, rect.getWidth());
    EXPECT_NE(height, rect.getHeight());

    EXPECT_EQ(left, rect2.getLeft());
    EXPECT_EQ(top, rect2.getTop());
    EXPECT_EQ(width, rect2.getWidth());
    EXPECT_EQ(height, rect2.getHeight());
}

TEST_F(TestRect, GetLeft) {
    EXPECT_EQ(0, rect.getLeft());

    Rect<float> rect2(1, 2, 3, 4);
    EXPECT_EQ(1, rect2.getLeft());
}

TEST_F(TestRect, GetTop) {
    EXPECT_EQ(0, rect.getTop());

    Rect<float> rect2(1, 2, 3, 4);
    EXPECT_EQ(2, rect2.getTop());
}

TEST_F(TestRect, GetWidth) {
    EXPECT_EQ(0, rect.getWidth());

    Rect<float> rect2(1, 2, 3, 4);
    EXPECT_EQ(3, rect2.getWidth());
}

TEST_F(TestRect, GetHeight) {
    EXPECT_EQ(0, rect.getHeight());

    Rect<float> rect2(1, 2, 3, 4);
    EXPECT_EQ(4, rect2.getHeight());
}

TEST_F(TestRect, Contains) {
    EXPECT_TRUE(rect.contains(0, 0));
    EXPECT_FALSE(rect.contains(1, 1));

    Rect<float> rect2(0, 0, 10, 10);
    EXPECT_TRUE(rect2.contains(0, 0));
    EXPECT_TRUE(rect2.contains(5, 5));
    EXPECT_TRUE(rect2.contains(10, 10));
    EXPECT_FALSE(rect2.contains(11, 11));
}
