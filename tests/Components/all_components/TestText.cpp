#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Text.h"

class TextTest : public ::testing::Test {
protected:
    Text text;

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(TextTest, Constructor) {
    Text text;

    ASSERT_EQ(text.getText().getString(), "");
}

TEST_F(TextTest, GetBit) {
    ASSERT_EQ(text.getBit(), 4);
}

TEST_F(TextTest, Update) {
    ASSERT_EQ(text.getTransform(), nullptr);

    testing::internal::CaptureStderr();

    text.update(sf::Time::Zero);

    std::string output = testing::internal::GetCapturedStderr();

    ASSERT_THAT(output, ::testing::HasSubstr("Please set the Text's Transform Component before updating it."));

    Transform transform;

    text.setTransform(transform);

    ASSERT_EQ(text.getTransform(), &transform);

    text.update(sf::Time::Zero);

    ASSERT_EQ(text.getText().getPosition(), sf::Vector2f(0, 0));
    ASSERT_EQ(text.getText().getRotation(), 0);
    ASSERT_EQ(text.getText().getScale(), sf::Vector2f(1, 1));

    text.getTransform()->setPosition(Vector2<float>(10, 10));
    text.getTransform()->setRotation(10);
    text.getTransform()->setScale(Vector2<float>(10, 10));

    text.update(sf::Time::Zero);

    ASSERT_EQ(text.getText().getPosition(), sf::Vector2f(10, 10));
    ASSERT_EQ(text.getText().getRotation(), 10);
    ASSERT_EQ(text.getText().getScale(), sf::Vector2f(10, 10));
}

TEST_F(TextTest, Init) {
    ASSERT_EQ(text.init(), false);

    Transform transform;

    text.setTransform(transform);

    ASSERT_EQ(text.init(), true);
}

TEST_F(TextTest, SetText1) {
    ASSERT_EQ(text.getText().getString(), "");

    std::map<std::string, std::shared_ptr<sf::Font>> mapFont;
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    mapFont["test"] = font;

    Color color;

    text.setText(mapFont, "test", "Hello world", 10, color);

    ASSERT_EQ(text.getText().getString(), "Hello world");
    ASSERT_EQ(text.getText().getCharacterSize(), 10);
    ASSERT_EQ(text.getText().getFillColor(), sf::Color(255, 255, 255));
    ASSERT_EQ(text.getText().getOutlineColor(), sf::Color(0, 0, 0));

    text.setText(mapFont, "test", "Hello world", 10, color, color);

    ASSERT_EQ(text.getText().getString(), "Hello world");
    ASSERT_EQ(text.getText().getCharacterSize(), 10);
    ASSERT_EQ(text.getText().getFillColor(), sf::Color(255, 255, 255));
    ASSERT_EQ(text.getText().getOutlineColor(), sf::Color(255, 255, 255));
}

TEST_F(TextTest, SetText2) {
    ASSERT_EQ(text.getText().getString(), "");

    std::map<std::string, std::shared_ptr<sf::Font>> mapFont;
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    mapFont["test"] = font;

    Color color;

    text.setText(mapFont, "test", "Hello world", 10, color);

    ASSERT_EQ(text.getText().getString(), "Hello world");
    ASSERT_EQ(text.getText().getCharacterSize(), 10);
    ASSERT_EQ(text.getText().getFillColor(), sf::Color(255, 255, 255));
    ASSERT_EQ(text.getText().getOutlineColor(), sf::Color(0, 0, 0));

    text.setText(mapFont, "test", "Hello world", 10, color, color);

    ASSERT_EQ(text.getText().getString(), "Hello world");
    ASSERT_EQ(text.getText().getCharacterSize(), 10);
    ASSERT_EQ(text.getText().getFillColor(), sf::Color(255, 255, 255));
    ASSERT_EQ(text.getText().getOutlineColor(), sf::Color(255, 255, 255));
}

TEST_F(TextTest, SetFont) {
    ASSERT_EQ(text.getText().getFont(), nullptr);

    std::map<std::string, std::shared_ptr<sf::Font>> mapFont;
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();

    font->loadFromFile("tests/assets/Fonts/test1.ttf");
    mapFont["test"] = font;

    std::shared_ptr<sf::Font> mapFont2 = std::make_shared<sf::Font>();

    mapFont2->loadFromFile("tests/assets/Fonts/test2.ttf");
    mapFont["test2"] = mapFont2;

    text.setFont(mapFont, "test");

    ASSERT_EQ(text.getFont().getInfo().family, "Roboto");

    text.setFont(mapFont, "test2");

    ASSERT_EQ(text.getFont().getInfo().family, "Roboto");
}

TEST_F(TextTest, SetString) {
    ASSERT_EQ(text.getText().getString(), "");

    text.setString("Hello world");

    ASSERT_EQ(text.getText().getString(), "Hello world");

    text.setString("Hello world 2");

    ASSERT_EQ(text.getText().getString(), "Hello world 2");
}

TEST_F(TextTest, SetSize) {
    ASSERT_EQ(text.getText().getCharacterSize(), 30);

    text.setSize(10);

    ASSERT_EQ(text.getText().getCharacterSize(), 10);

    text.setSize(20);

    ASSERT_EQ(text.getText().getCharacterSize(), 20);
}

TEST_F(TextTest, SetOutlineColor) {
    ASSERT_EQ(text.getText().getOutlineColor(), sf::Color(0, 0, 0));

    Color color;

    text.setOutlineColor(color);

    ASSERT_EQ(text.getText().getOutlineColor(), sf::Color(255, 255, 255));

    text.setOutlineColor(color);

    ASSERT_EQ(text.getText().getOutlineColor(), sf::Color(255, 255, 255));
}

TEST_F(TextTest, SetFillColor) {
    ASSERT_EQ(text.getText().getFillColor(), sf::Color(255, 255, 255));

    Color color;

    text.setFillColor(color);

    ASSERT_EQ(text.getText().getFillColor(), sf::Color(255, 255, 255));

    text.setFillColor(color);

    ASSERT_EQ(text.getText().getFillColor(), sf::Color(255, 255, 255));
}

TEST_F(TextTest, GetText) {
    ASSERT_EQ(text.getText().getString(), "");

    std::map<std::string, std::shared_ptr<sf::Font>> mapFont;
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    mapFont["test"] = font;

    Color color;

    text.setText(mapFont, "test", "Hello world", 10, color);

    ASSERT_EQ(text.getText().getString(), "Hello world");
    ASSERT_EQ(text.getText().getCharacterSize(), 10);
    ASSERT_EQ(text.getText().getFillColor(), sf::Color(255, 255, 255));
    ASSERT_EQ(text.getText().getOutlineColor(), sf::Color(0, 0, 0));

    text.setText(mapFont, "test", "Hello world", 10, color, color);

    ASSERT_EQ(text.getText().getString(), "Hello world");
    ASSERT_EQ(text.getText().getCharacterSize(), 10);
    ASSERT_EQ(text.getText().getFillColor(), sf::Color(255, 255, 255));
    ASSERT_EQ(text.getText().getOutlineColor(), sf::Color(255, 255, 255));
}

TEST_F(TextTest, GetFont) {
    ASSERT_EQ(text.getFont().getInfo().family, "");

    std::map<std::string, std::shared_ptr<sf::Font>> mapFont;

    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();

    font->loadFromFile("tests/assets/Fonts/test1.ttf");
    mapFont["test"] = font;

    std::shared_ptr<sf::Font> mapFont2 = std::make_shared<sf::Font>();

    mapFont2->loadFromFile("tests/assets/Fonts/test2.ttf");

    mapFont["test2"] = mapFont2;

    text.setFont(mapFont, "test");

    ASSERT_EQ(text.getFont().getInfo().family, "Roboto");

    text.setFont(mapFont, "test2");

    ASSERT_EQ(text.getFont().getInfo().family, "Roboto");
}

TEST_F(TextTest, GetStringText) {
    ASSERT_EQ(text.getStringText(), "");

    text.setString("Hello world");

    ASSERT_EQ(text.getStringText(), "Hello world");

    text.setString("Hello world 2");

    ASSERT_EQ(text.getStringText(), "Hello world 2");
}

TEST_F(TextTest, GetSize) {
    ASSERT_EQ(text.getSize(), 0);

    text.setSize(10);

    ASSERT_EQ(text.getSize(), 10);

    text.setSize(20);

    ASSERT_EQ(text.getSize(), 20);
}

TEST_F(TextTest, GetColorFill) {
    Color color;

    ASSERT_EQ(text.getColorFill().getRed(), color.getRed());
    ASSERT_EQ(text.getColorFill().getGreen(), color.getGreen());
    ASSERT_EQ(text.getColorFill().getBlue(), color.getBlue());

    Color newColor;

    newColor.setRed(15);
    newColor.setGreen(15);
    newColor.setBlue(15);

    text.setFillColor(newColor);

    ASSERT_NE(text.getColorFill().getRed(), color.getRed());
    ASSERT_NE(text.getColorFill().getGreen(), color.getGreen());
    ASSERT_NE(text.getColorFill().getBlue(), color.getBlue());

    ASSERT_EQ(text.getColorFill().getRed(), newColor.getRed());
    ASSERT_EQ(text.getColorFill().getGreen(), newColor.getGreen());
    ASSERT_EQ(text.getColorFill().getBlue(), newColor.getBlue());
}

TEST_F(TextTest, GetColorOutline) {
    Color color;

    ASSERT_EQ(text.getColorOutline().getRed(), color.getRed());
    ASSERT_EQ(text.getColorOutline().getGreen(), color.getGreen());
    ASSERT_EQ(text.getColorOutline().getBlue(), color.getBlue());

    Color newColor;

    newColor.setRed(15);
    newColor.setGreen(15);
    newColor.setBlue(15);

    text.setOutlineColor(newColor);

    ASSERT_NE(text.getColorOutline().getRed(), color.getRed());
    ASSERT_NE(text.getColorOutline().getGreen(), color.getGreen());
    ASSERT_NE(text.getColorOutline().getBlue(), color.getBlue());

    ASSERT_EQ(text.getColorOutline().getRed(), newColor.getRed());
    ASSERT_EQ(text.getColorOutline().getGreen(), newColor.getGreen());
    ASSERT_EQ(text.getColorOutline().getBlue(), newColor.getBlue());
}

TEST_F(TextTest, SetAndGetTransform) {
    ASSERT_EQ(text.getTransform(), nullptr);

    Transform transform;

    text.setTransform(transform);

    ASSERT_EQ(text.getTransform(), &transform);

    Transform newTransform;

    newTransform.setPosition(Vector2<float>(10, 10));
    newTransform.setRotation(10);
    newTransform.setScale(Vector2<float>(10, 10));

    text.setTransform(newTransform);

    ASSERT_NE(text.getTransform(), nullptr);
    ASSERT_EQ(text.getTransform(), &newTransform);
}

TEST_F(TextTest, SetAndApplyDeferredText) {
    ASSERT_EQ(text.getTransform(), nullptr);

    Transform transform;

    text.setTransform(transform);

    ASSERT_EQ(text.getTransform(), &transform);

    auto helloWorldFunction = []() { std::cout << "Hello world" << std::endl; };

    text.setDeferredText(helloWorldFunction);

    testing::internal::CaptureStdout();

    text.applyDeferredText();

    std::string output = testing::internal::GetCapturedStdout();
}
