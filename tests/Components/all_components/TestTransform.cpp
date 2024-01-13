#include <gtest/gtest.h>
#include "Transform.h"

class TransformTest : public ::testing::Test {
protected:
    Transform transform;

    void SetUp() override {
        transform = Transform();
    }

    void TearDown() override {
    }
};

TEST_F(TransformTest, Constructor) {
    EXPECT_EQ(0, transform.getBit());

    int x = 0;
    int y = 0;

    EXPECT_EQ(x, transform.getPosition().getX());
    EXPECT_EQ(y, transform.getPosition().getY());

    EXPECT_EQ(0, transform.getRotation());

    EXPECT_EQ(1.0, transform.getScale().getX());
    EXPECT_EQ(1.0, transform.getScale().getY());
}

TEST_F(TransformTest, Init) {
    EXPECT_TRUE(transform.init());
}

TEST_F(TransformTest, GetBit) {
    EXPECT_EQ(0, transform.getBit());
}

TEST_F(TransformTest, GetPosition) {
    int x = 0;
    int y = 0;

    EXPECT_EQ(x, transform.getPosition().getX());
    EXPECT_EQ(y, transform.getPosition().getY());

    transform.setTransformPosition(Vector2<float>(1.0f, 1.0f));

    EXPECT_NE(x, transform.getPosition().getX());
    EXPECT_NE(y, transform.getPosition().getY());

    EXPECT_EQ(1.0f, transform.getPosition().getX());
    EXPECT_EQ(1.0f, transform.getPosition().getY());
}

TEST_F(TransformTest, GetRotation) {
    EXPECT_EQ(0, transform.getRotation());

    transform.setTransformRotation(1.0f);

    EXPECT_NE(0, transform.getRotation());
    EXPECT_EQ(1.0f, transform.getRotation());
}

TEST_F(TransformTest, GetScale) {
    int x = 1;
    int y = 1;

    EXPECT_EQ(x, transform.getScale().getX());
    EXPECT_EQ(y, transform.getScale().getY());

    transform.setTransformScale(Vector2<float>(2.0f, 2.0f));

    EXPECT_NE(x, transform.getScale().getX());
    EXPECT_NE(y, transform.getScale().getY());

    EXPECT_EQ(2.0f, transform.getScale().getX());
    EXPECT_EQ(2.0f, transform.getScale().getY());
}

TEST_F(TransformTest, GetTransformStruct) {
    Transform testTransform;

    EXPECT_EQ(testTransform.getPosition().getX(), transform.getTransformStruct().position.getX());
    EXPECT_EQ(testTransform.getPosition().getY(), transform.getTransformStruct().position.getY());

    EXPECT_EQ(testTransform.getRotation(), transform.getTransformStruct().rotation);

    EXPECT_EQ(testTransform.getScale().getX(), transform.getTransformStruct().scale.getX());
    EXPECT_EQ(testTransform.getScale().getY(), transform.getTransformStruct().scale.getY());

    transform.setTransform(Vector2<float>(1.0f, 1.0f), 1.0f, Vector2<float>(2.0f, 2.0f));

    EXPECT_NE(testTransform.getPosition().getX(), transform.getTransformStruct().position.getX());
    EXPECT_NE(testTransform.getPosition().getY(), transform.getTransformStruct().position.getY());

    EXPECT_NE(testTransform.getRotation(), transform.getTransformStruct().rotation);

    EXPECT_NE(testTransform.getScale().getX(), transform.getTransformStruct().scale.getX());
    EXPECT_NE(testTransform.getScale().getY(), transform.getTransformStruct().scale.getY());

    EXPECT_EQ(1.0f, transform.getTransformStruct().position.getX());
    EXPECT_EQ(1.0f, transform.getTransformStruct().position.getY());

    EXPECT_EQ(1.0f, transform.getTransformStruct().rotation);

    EXPECT_EQ(2.0f, transform.getTransformStruct().scale.getX());
    EXPECT_EQ(2.0f, transform.getTransformStruct().scale.getY());
}

TEST_F(TransformTest, SetTransform) {
    Transform testTransform;

    EXPECT_EQ(testTransform.getPosition().getX(), transform.getTransformStruct().position.getX());
    EXPECT_EQ(testTransform.getPosition().getY(), transform.getTransformStruct().position.getY());

    EXPECT_EQ(testTransform.getRotation(), transform.getTransformStruct().rotation);

    EXPECT_EQ(testTransform.getScale().getX(), transform.getTransformStruct().scale.getX());
    EXPECT_EQ(testTransform.getScale().getY(), transform.getTransformStruct().scale.getY());

    transform.setTransform(Vector2<float>(1.0f, 1.0f), 1.0f, Vector2<float>(2.0f, 2.0f));

    EXPECT_NE(testTransform.getPosition().getX(), transform.getTransformStruct().position.getX());
    EXPECT_NE(testTransform.getPosition().getY(), transform.getTransformStruct().position.getY());

    EXPECT_NE(testTransform.getRotation(), transform.getTransformStruct().rotation);

    EXPECT_NE(testTransform.getScale().getX(), transform.getTransformStruct().scale.getX());
    EXPECT_NE(testTransform.getScale().getY(), transform.getTransformStruct().scale.getY());

    EXPECT_EQ(1.0f, transform.getTransformStruct().position.getX());
    EXPECT_EQ(1.0f, transform.getTransformStruct().position.getY());

    EXPECT_EQ(1.0f, transform.getTransformStruct().rotation);

    EXPECT_EQ(2.0f, transform.getTransformStruct().scale.getX());
    EXPECT_EQ(2.0f, transform.getTransformStruct().scale.getY());
}

TEST_F(TransformTest, SetTransformPosition) {
    int x = 0;
    int y = 0;

    EXPECT_EQ(x, transform.getPosition().getX());
    EXPECT_EQ(y, transform.getPosition().getY());

    transform.setTransformPosition(Vector2<float>(1.0f, 1.0f));

    EXPECT_NE(x, transform.getPosition().getX());
    EXPECT_NE(y, transform.getPosition().getY());

    EXPECT_EQ(1.0f, transform.getPosition().getX());
    EXPECT_EQ(1.0f, transform.getPosition().getY());
}

TEST_F(TransformTest, SetTransformRotation) {
    EXPECT_EQ(0, transform.getRotation());

    transform.setTransformRotation(1.0f);

    EXPECT_NE(0, transform.getRotation());
    EXPECT_EQ(1.0f, transform.getRotation());
}

TEST_F(TransformTest, SetTransformScale) {
    int x = 1;
    int y = 1;

    EXPECT_EQ(x, transform.getScale().getX());
    EXPECT_EQ(y, transform.getScale().getY());

    transform.setTransformScale(Vector2<float>(2.0f, 2.0f));

    EXPECT_NE(x, transform.getScale().getX());
    EXPECT_NE(y, transform.getScale().getY());

    EXPECT_EQ(2.0f, transform.getScale().getX());
    EXPECT_EQ(2.0f, transform.getScale().getY());
}
