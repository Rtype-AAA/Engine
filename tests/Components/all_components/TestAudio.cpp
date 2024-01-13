#include <gtest/gtest.h>
#include "Audio.h"

class AudioTest : public ::testing::Test {
protected:
    Audio audio;

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(AudioTest, DefaultConstructor) {
Audio audio;

EXPECT_EQ(audio.getSoundBuffer().getDuration(), sf::Time::Zero);
EXPECT_EQ(audio.getSound().getBuffer(), nullptr);
}

TEST_F(AudioTest, ConstructorWithSoundBuffer) {
sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/powerup.ogg"));

Audio newAudio(buffer);

sf::Time time = newAudio.getSoundBuffer().getDuration();

EXPECT_TRUE(newAudio.getSoundBuffer().getDuration() > sf::Time::Zero);
EXPECT_NE(newAudio.getSound().getBuffer(), nullptr);
}

TEST_F(AudioTest, LoadSoundBuffer) {
EXPECT_FALSE(audio.loadSoundBuffer("tests/assets/sounds/does_not_exist.ogg"));
EXPECT_TRUE(audio.loadSoundBuffer("tests/assets/sounds/powerup.ogg"));

EXPECT_TRUE(audio.getSoundBuffer().getDuration() > sf::Time::Zero);
EXPECT_NE(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/music.ogg"));

EXPECT_NE(&audio.getSoundBuffer(), &buffer);

EXPECT_TRUE(audio.setSoundBuffer(buffer));
EXPECT_EQ(audio.getSoundBuffer().getDuration(), buffer.getDuration());
EXPECT_NE(audio.getSound().getBuffer(), nullptr);
}

TEST_F(AudioTest, SetSoundBuffer) {
EXPECT_EQ(audio.getSoundBuffer().getDuration(), sf::Time::Zero);
EXPECT_EQ(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/powerup.ogg"));

EXPECT_TRUE(audio.setSoundBuffer(buffer));
EXPECT_EQ(audio.getSoundBuffer().getDuration(), buffer.getDuration());
EXPECT_NE(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer otherBuffer;
EXPECT_TRUE(otherBuffer.loadFromFile("tests/assets/sounds/music.ogg"));

EXPECT_NE(audio.getSoundBuffer().getDuration(), otherBuffer.getDuration());
EXPECT_NE(&audio.getSoundBuffer(), &otherBuffer);

EXPECT_TRUE(audio.setSoundBuffer(otherBuffer));
EXPECT_EQ(audio.getSoundBuffer().getDuration(), otherBuffer.getDuration());
EXPECT_NE(audio.getSoundBuffer().getDuration(), buffer.getDuration());
EXPECT_NE(audio.getSound().getBuffer(), nullptr);
}

TEST_F(AudioTest, GetSoundBuffer) {
EXPECT_EQ(audio.getSoundBuffer().getDuration(), sf::Time::Zero);
EXPECT_EQ(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/powerup.ogg"));

EXPECT_TRUE(audio.setSoundBuffer(buffer));

sf::SoundBuffer audioBuffer = audio.getSoundBuffer();

EXPECT_EQ(audioBuffer.getDuration(), buffer.getDuration());
EXPECT_NE(&audioBuffer, &buffer);

sf::SoundBuffer otherBuffer;
EXPECT_TRUE(otherBuffer.loadFromFile("tests/assets/sounds/music.ogg"));

EXPECT_NE(audioBuffer.getDuration(), otherBuffer.getDuration());
EXPECT_NE(&audioBuffer, &otherBuffer);

EXPECT_TRUE(audio.setSoundBuffer(otherBuffer));
audioBuffer = audio.getSoundBuffer();

EXPECT_EQ(audioBuffer.getDuration(), otherBuffer.getDuration());
EXPECT_NE(audioBuffer.getDuration(), buffer.getDuration());
EXPECT_NE(audio.getSound().getBuffer(), nullptr);
}

TEST_F(AudioTest, SetSound) {
EXPECT_EQ(audio.getSoundBuffer().getDuration(), sf::Time::Zero);
EXPECT_EQ(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/powerup.ogg"));

sf::Sound sound;
sound.setBuffer(buffer);

EXPECT_TRUE(audio.setSound(sound));
EXPECT_EQ(audio.getSoundBuffer().getDuration(), buffer.getDuration());
EXPECT_NE(audio.getSound().getBuffer(), nullptr);

sf::Sound otherSound;
sf::SoundBuffer otherBuffer;
EXPECT_TRUE(otherBuffer.loadFromFile("tests/assets/sounds/music.ogg"));
otherSound.setBuffer(otherBuffer);

EXPECT_NE(audio.getSoundBuffer().getDuration(), otherBuffer.getDuration());
EXPECT_NE(&audio.getSoundBuffer(), &otherBuffer);

EXPECT_TRUE(audio.setSound(otherSound));
EXPECT_EQ(audio.getSoundBuffer().getDuration(), otherBuffer.getDuration());
EXPECT_NE(audio.getSoundBuffer().getDuration(), buffer.getDuration());
EXPECT_NE(audio.getSound().getBuffer(), nullptr);
}

TEST_F(AudioTest, GetSound) {
EXPECT_EQ(audio.getSoundBuffer().getDuration(), sf::Time::Zero);
EXPECT_EQ(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/powerup.ogg"));

sf::Sound sound;
sound.setBuffer(buffer);

EXPECT_TRUE(audio.setSound(sound));

sf::Sound audioSound = audio.getSound();

EXPECT_EQ(audioSound.getBuffer()->getDuration(), buffer.getDuration());
EXPECT_NE(&audioSound, &sound);

sf::Sound otherSound;
sf::SoundBuffer otherBuffer;
EXPECT_TRUE(otherBuffer.loadFromFile("tests/assets/sounds/music.ogg"));
otherSound.setBuffer(otherBuffer);

EXPECT_NE(audioSound.getBuffer()->getDuration(), otherBuffer.getDuration());
EXPECT_NE(&audioSound, &otherSound);

EXPECT_TRUE(audio.setSound(otherSound));
audioSound = audio.getSound();

EXPECT_EQ(audioSound.getBuffer()->getDuration(), otherBuffer.getDuration());
EXPECT_NE(audioSound.getBuffer()->getDuration(), buffer.getDuration());
EXPECT_NE(audio.getSound().getBuffer(), nullptr);
}

TEST_F(AudioTest, Play) {
EXPECT_EQ(audio.getSoundBuffer().getDuration(), sf::Time::Zero);
EXPECT_EQ(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/music.ogg"));

EXPECT_TRUE(audio.setSoundBuffer(buffer));

audio.play();
EXPECT_TRUE(audio.isPlaying());
}

TEST_F(AudioTest, Pause) {
EXPECT_EQ(audio.getSoundBuffer().getDuration(), sf::Time::Zero);
EXPECT_EQ(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/music.ogg"));

EXPECT_TRUE(audio.setSoundBuffer(buffer));

audio.play();
EXPECT_TRUE(audio.isPlaying());

audio.pause();
EXPECT_FALSE(audio.isPlaying());
}

TEST_F(AudioTest, Stop) {
EXPECT_EQ(audio.getSoundBuffer().getDuration(), sf::Time::Zero);
EXPECT_EQ(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/music.ogg"));

EXPECT_TRUE(audio.setSoundBuffer(buffer));

audio.play();
EXPECT_TRUE(audio.isPlaying());

audio.stop();
EXPECT_FALSE(audio.isPlaying());
}

TEST_F(AudioTest, SetLoop) {
EXPECT_FALSE(audio.getSound().getLoop());

audio.setLoop(true);
EXPECT_TRUE(audio.getSound().getLoop());

audio.setLoop(false);
EXPECT_FALSE(audio.getSound().getLoop());
}

TEST_F(AudioTest, SetVolume) {
EXPECT_EQ(audio.getSound().getVolume(), 100.f);

audio.setVolume(50.f);
EXPECT_EQ(audio.getSound().getVolume(), 50.f);

audio.setVolume(0.f);
EXPECT_EQ(audio.getSound().getVolume(), 0.f);

audio.setVolume(100.f);
EXPECT_EQ(audio.getSound().getVolume(), 100.f);
}

TEST_F(AudioTest, GetVolume) {
EXPECT_EQ(audio.getSound().getVolume(), 100.f);

audio.setVolume(50.f);
EXPECT_EQ(audio.getSound().getVolume(), 50.f);

audio.setVolume(0.f);
EXPECT_EQ(audio.getSound().getVolume(), 0.f);

audio.setVolume(100.f);
EXPECT_EQ(audio.getSound().getVolume(), 100.f);
}

TEST_F(AudioTest, IsPlaying) {
EXPECT_EQ(audio.getSoundBuffer().getDuration(), sf::Time::Zero);
EXPECT_EQ(audio.getSound().getBuffer(), nullptr);

sf::SoundBuffer buffer;
EXPECT_TRUE(buffer.loadFromFile("tests/assets/sounds/music.ogg"));

EXPECT_TRUE(audio.setSoundBuffer(buffer));

EXPECT_FALSE(audio.isPlaying());

audio.play();
EXPECT_TRUE(audio.isPlaying());

audio.setLoop(true);

audio.pause();
EXPECT_FALSE(audio.isPlaying());

audio.play();
EXPECT_TRUE(audio.isPlaying());

audio.stop();
EXPECT_FALSE(audio.isPlaying());
}