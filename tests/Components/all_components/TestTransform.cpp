#include <gtest/gtest.h>
#include "../../../include/all_components.h"

// Test fixture for Transform class
class TransformTest : public ::testing::Test {
protected:
    Transform transform;
};

// Test case for getBit() function
TEST_F(TransformTest, GetBit) {
    EXPECT_EQ(0, transform.getBit());
}

// Test case for getPositionVector() function
TEST_F(TransformTest, GetPositionVector) {
    std::vector<float> expectedPosition = {0.0f, 0.0f};
    EXPECT_EQ(expectedPosition, transform.getPositionVector());
}

// Test case for getRotationVector() function
TEST_F(TransformTest, GetRotationVector) {
    std::vector<float> expectedRotation = {0.0f, 0.0f};
    EXPECT_EQ(expectedRotation, transform.getRotationVector());
}

// Test case for getScaleVector() function
TEST_F(TransformTest, GetScaleVector) {
    std::vector<float> expectedScale = {1.0f, 1.0f};
    EXPECT_EQ(expectedScale, transform.getScaleVector());
}

// Test case for setTransform() function
TEST_F(TransformTest, SetTransform) {
    std::map<std::string, std::vector<float>> transformData = {
        {"Position", {1.0f, 2.0f}},
        {"Rotation", {3.0f, 4.0f}},
        {"Scale", {5.0f, 6.0f}}
    };

    transform.setTransform(transformData);

    EXPECT_EQ(0, transform.getBit());
    EXPECT_EQ(std::vector<float>({1.0f, 2.0f}), transform.getPositionVector());
    EXPECT_EQ(std::vector<float>({3.0f, 4.0f}), transform.getRotationVector());
    EXPECT_EQ(std::vector<float>({5.0f, 6.0f}), transform.getScaleVector());
}
