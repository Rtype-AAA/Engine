#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Sound.h"

class SoundTest : public ::testing::Test
{
protected:
    Sound sound;

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(SoundTest, Constructor) {
    ASSERT_EQ(sound.getBit(), 2);
    ASSERT_EQ(sound.init(), true);

    ASSERT_EQ(sound.getSound().getBuffer(), nullptr);
    ASSERT_EQ(sound.getSound().getVolume(), 100);
    ASSERT_EQ(sound.getSound().getPitch(), 1);
}

TEST_F(SoundTest, GetBit) {
    ASSERT_EQ(sound.getBit(), 2);
}

TEST_F(SoundTest, Update) {
    EXPECT_NO_THROW(sound.update(sf::Time::Zero));
}

TEST_F(SoundTest, Init) {
    ASSERT_EQ(sound.init(), true);
}

TEST_F(SoundTest, SetSoundWithSfSound) {
    ASSERT_EQ(sound.getSound().getBuffer(), nullptr);

    sf::Sound sfSound;
    sf::SoundBuffer buffer;

    buffer.loadFromFile("tests/assets/Sounds/test1.ogg");
    sfSound.setBuffer(buffer);

    sound.setSound(sfSound);

    ASSERT_NE(sound.getSound().getBuffer(), nullptr);
    ASSERT_EQ(sound.getSound().getBuffer(), &buffer);
}

TEST_F(SoundTest, SetSound) {
    ASSERT_EQ(sound.getSound().getBuffer(), nullptr);

    std::map<std::string, std::shared_ptr<sf::SoundBuffer>> mapSound;
    std::shared_ptr<sf::SoundBuffer> soundBuffer = std::make_shared<sf::SoundBuffer>();
    mapSound["test"] = soundBuffer;

    sound.setSound(mapSound, "test");
    ASSERT_EQ(sound.getSound().getBuffer(), soundBuffer.get());
}

TEST_F(SoundTest, SetAndApplyDeferredSound) {
    auto helloWorldFunction = []() { std::cout << "Hello world" << std::endl; };

    sound.setDeferredSound(helloWorldFunction);

    testing::internal::CaptureStdout();

    sound.applyDeferredSound();

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_THAT(output, ::testing::HasSubstr("Hello world"));
}

TEST_F(SoundTest, GetSound) {
    ASSERT_EQ(sound.getSound().getBuffer(), nullptr);

    std::map<std::string, std::shared_ptr<sf::SoundBuffer>> mapSound;
    std::shared_ptr<sf::SoundBuffer> soundBuffer = std::make_shared<sf::SoundBuffer>();

    mapSound["test"] = soundBuffer;

    sound.setSound(mapSound, "test");
    ASSERT_EQ(sound.getSound().getBuffer(), soundBuffer.get());

    ASSERT_EQ(sound.getSound().getVolume(), 100);
    ASSERT_EQ(sound.getSound().getPitch(), 1);

    Sound newSound;

    ASSERT_EQ(newSound.getSound().getBuffer(), nullptr);

    sf::Sound sfSound;
    sf::SoundBuffer buffer;

    buffer.loadFromFile("tests/assets/Sounds/test1.ogg");
    sfSound.setBuffer(buffer);

    newSound.setSound(sfSound);

    ASSERT_NE(newSound.getSound().getBuffer(), nullptr);
    ASSERT_EQ(newSound.getSound().getBuffer(), &buffer);
}

TEST_F(SoundTest, Play) {
    sound.play();

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Stopped);

    sf::Sound sfSound;
    sf::SoundBuffer buffer;

    buffer.loadFromFile("tests/assets/Sounds/test1.ogg");
    sfSound.setBuffer(buffer);

    sound.setSound(sfSound);

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Stopped);

    sound.play();

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Playing);
}

TEST_F(SoundTest, Pause) {
    sound.pause();

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Stopped);

    sf::Sound sfSound;
    sf::SoundBuffer buffer;

    buffer.loadFromFile("tests/assets/Sounds/test1.ogg");
    sfSound.setBuffer(buffer);

    sound.setSound(sfSound);

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Stopped);

    sound.play();

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Playing);

    sound.pause();

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Paused);
}

TEST_F(SoundTest, Stop) {
    sf::Sound sfSound;
    sf::SoundBuffer buffer;

    buffer.loadFromFile("tests/assets/Sounds/test1.ogg");
    sfSound.setBuffer(buffer);

    sound.setSound(sfSound);

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Stopped);

    sound.play();

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Playing);

    sound.stop();

    ASSERT_EQ(sound.getSound().getStatus(), sf::SoundSource::Status::Stopped);
}

TEST_F(SoundTest, SetLoop) {
    ASSERT_EQ(sound.getSound().getLoop(), false);

    sound.setLoop(true);

    ASSERT_EQ(sound.getSound().getLoop(), true);

    sound.setLoop(false);

    ASSERT_EQ(sound.getSound().getLoop(), false);
}

TEST_F(SoundTest, GetLoop) {
    ASSERT_EQ(sound.getLoop(), sound.getSound().getLoop());
    ASSERT_EQ(sound.getLoop(), false);

    sound.setLoop(true);

    ASSERT_EQ(sound.getLoop(), sound.getSound().getLoop());
    ASSERT_EQ(sound.getLoop(), true);

    sound.setLoop(false);

    ASSERT_EQ(sound.getLoop(), sound.getSound().getLoop());
    ASSERT_EQ(sound.getLoop(), false);
}

TEST_F(SoundTest, SetVolume) {
    ASSERT_EQ(sound.getSound().getVolume(), 100);

    sound.setVolume(50);

    ASSERT_EQ(sound.getSound().getVolume(), 50);

    sound.setVolume(100);

    ASSERT_EQ(sound.getSound().getVolume(), 100);
}

TEST_F(SoundTest, GetVolume) {
    ASSERT_EQ(sound.getVolume(), sound.getSound().getVolume());
    ASSERT_EQ(sound.getVolume(), 100);

    sound.setVolume(50);

    ASSERT_EQ(sound.getVolume(), sound.getSound().getVolume());
    ASSERT_EQ(sound.getVolume(), 50);

    sound.setVolume(100);

    ASSERT_EQ(sound.getVolume(), sound.getSound().getVolume());
    ASSERT_EQ(sound.getVolume(), 100);
}

TEST_F(SoundTest, IsPlaying) {
    sf::Sound sfSound;
    sf::SoundBuffer buffer;

    buffer.loadFromFile("tests/assets/Sounds/test1.ogg");
    sfSound.setBuffer(buffer);

    sound.setSound(sfSound);

    ASSERT_EQ(sound.isPlaying(), false);

    sound.play();

    ASSERT_EQ(sound.isPlaying(), true);

    sound.pause();

    ASSERT_EQ(sound.isPlaying(), false);

    sound.play();

    ASSERT_EQ(sound.isPlaying(), true);

    sound.stop();

    ASSERT_EQ(sound.isPlaying(), false);
}
