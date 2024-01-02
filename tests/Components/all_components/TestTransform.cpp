#include <gtest/gtest.h>
#include "../../../src/include/all_components.h"

class TransformTest : public ::testing::Test {
protected:
    Transform transform;
};

TEST_F(TransformTest, GetBit) {
    EXPECT_EQ(0, transform.getBit());
}

TEST_F(TransformTest, GetPositionVector) {
    std::vector<float> expectedPosition = {0.0f, 0.0f};
    EXPECT_EQ(expectedPosition, transform.getPositionVector());
}

TEST_F(TransformTest, GetRotationVector) {
    std::vector<float> expectedRotation = {0.0f, 0.0f};
    EXPECT_EQ(expectedRotation, transform.getRotationVector());
}

TEST_F(TransformTest, GetScaleVector) {
    std::vector<float> expectedScale = {1.0f, 1.0f};
    EXPECT_EQ(expectedScale, transform.getScaleVector());
}

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
