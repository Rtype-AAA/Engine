#include <gtest/gtest.h>
#include <gmock/gmock.h>
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

TEST_F(TransformTest, Update) {
    auto helloWorldFunction = []() { std::cout << "Hello world" << std::endl; };

    transform.setDeferredTransform(helloWorldFunction);

    testing::internal::CaptureStdout();

    transform.update(sf::seconds(1.0f));

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_THAT(output, ::testing::HasSubstr("Hello world"));
}

TEST_F(TransformTest, GetPosition) {
    int x = 0;
    int y = 0;

    EXPECT_EQ(x, transform.getPosition().getX());
    EXPECT_EQ(y, transform.getPosition().getY());

    transform.setPosition(Vector2<float>(1.0f, 1.0f));

    EXPECT_NE(x, transform.getPosition().getX());
    EXPECT_NE(y, transform.getPosition().getY());

    EXPECT_EQ(1.0f, transform.getPosition().getX());
    EXPECT_EQ(1.0f, transform.getPosition().getY());
}

TEST_F(TransformTest, GetRotation) {
    EXPECT_EQ(0, transform.getRotation());

    transform.setRotation(1.0f);

    EXPECT_NE(0, transform.getRotation());
    EXPECT_EQ(1.0f, transform.getRotation());
}

TEST_F(TransformTest, GetScale) {
    int x = 1;
    int y = 1;

    EXPECT_EQ(x, transform.getScale().getX());
    EXPECT_EQ(y, transform.getScale().getY());

    transform.setScale(Vector2<float>(2.0f, 2.0f));

    EXPECT_NE(x, transform.getScale().getX());
    EXPECT_NE(y, transform.getScale().getY());

    EXPECT_EQ(2.0f, transform.getScale().getX());
    EXPECT_EQ(2.0f, transform.getScale().getY());
}

TEST_F(TransformTest, GetTransform) {
    Transform testTransform;

    EXPECT_EQ(testTransform.getPosition().getX(), transform.getTransform().position.getX());
    EXPECT_EQ(testTransform.getPosition().getY(), transform.getTransform().position.getY());

    EXPECT_EQ(testTransform.getRotation(), transform.getTransform().rotation);

    EXPECT_EQ(testTransform.getScale().getX(), transform.getTransform().scale.getX());
    EXPECT_EQ(testTransform.getScale().getY(), transform.getTransform().scale.getY());

    transform.setTransform(Vector2<float>(1.0f, 1.0f), 1.0f, Vector2<float>(2.0f, 2.0f));

    EXPECT_NE(testTransform.getPosition().getX(), transform.getTransform().position.getX());
    EXPECT_NE(testTransform.getPosition().getY(), transform.getTransform().position.getY());

    EXPECT_NE(testTransform.getRotation(), transform.getTransform().rotation);

    EXPECT_NE(testTransform.getScale().getX(), transform.getTransform().scale.getX());
    EXPECT_NE(testTransform.getScale().getY(), transform.getTransform().scale.getY());

    EXPECT_EQ(1.0f, transform.getTransform().position.getX());
    EXPECT_EQ(1.0f, transform.getTransform().position.getY());

    EXPECT_EQ(1.0f, transform.getTransform().rotation);

    EXPECT_EQ(2.0f, transform.getTransform().scale.getX());
    EXPECT_EQ(2.0f, transform.getTransform().scale.getY());
}

TEST_F(TransformTest, SetTransform) {
    Transform testTransform;

    EXPECT_EQ(testTransform.getPosition().getX(), transform.getTransform().position.getX());
    EXPECT_EQ(testTransform.getPosition().getY(), transform.getTransform().position.getY());

    EXPECT_EQ(testTransform.getRotation(), transform.getTransform().rotation);

    EXPECT_EQ(testTransform.getScale().getX(), transform.getTransform().scale.getX());
    EXPECT_EQ(testTransform.getScale().getY(), transform.getTransform().scale.getY());

    transform.setTransform(Vector2<float>(1.0f, 1.0f), 1.0f, Vector2<float>(2.0f, 2.0f));

    EXPECT_NE(testTransform.getPosition().getX(), transform.getTransform().position.getX());
    EXPECT_NE(testTransform.getPosition().getY(), transform.getTransform().position.getY());

    EXPECT_NE(testTransform.getRotation(), transform.getTransform().rotation);

    EXPECT_NE(testTransform.getScale().getX(), transform.getTransform().scale.getX());
    EXPECT_NE(testTransform.getScale().getY(), transform.getTransform().scale.getY());

    EXPECT_EQ(1.0f, transform.getTransform().position.getX());
    EXPECT_EQ(1.0f, transform.getTransform().position.getY());

    EXPECT_EQ(1.0f, transform.getTransform().rotation);

    EXPECT_EQ(2.0f, transform.getTransform().scale.getX());
    EXPECT_EQ(2.0f, transform.getTransform().scale.getY());
}

TEST_F(TransformTest, SetPosition) {
    int x = 0;
    int y = 0;

    EXPECT_EQ(x, transform.getPosition().getX());
    EXPECT_EQ(y, transform.getPosition().getY());

    transform.setPosition(Vector2<float>(1.0f, 1.0f));

    EXPECT_NE(x, transform.getPosition().getX());
    EXPECT_NE(y, transform.getPosition().getY());

    EXPECT_EQ(1.0f, transform.getPosition().getX());
    EXPECT_EQ(1.0f, transform.getPosition().getY());
}

TEST_F(TransformTest, SetRotation) {
    EXPECT_EQ(0, transform.getRotation());

    transform.setRotation(1.0f);

    EXPECT_NE(0, transform.getRotation());
    EXPECT_EQ(1.0f, transform.getRotation());
}

TEST_F(TransformTest, SetScale) {
    int x = 1;
    int y = 1;

    EXPECT_EQ(x, transform.getScale().getX());
    EXPECT_EQ(y, transform.getScale().getY());

    transform.setScale(Vector2<float>(2.0f, 2.0f));

    EXPECT_NE(x, transform.getScale().getX());
    EXPECT_NE(y, transform.getScale().getY());

    EXPECT_EQ(2.0f, transform.getScale().getX());
    EXPECT_EQ(2.0f, transform.getScale().getY());
}

TEST_F(TransformTest, SetAndApplyDeferredTransform) {
    auto helloWorldFunction = []() { std::cout << "Hello world" << std::endl; };

    transform.setDeferredTransform(helloWorldFunction);

    testing::internal::CaptureStdout();

    transform.applyDeferredTransform();

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_THAT(output, ::testing::HasSubstr("Hello world"));
}
