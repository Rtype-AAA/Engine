//
// Created by thibaultcampagne on 30/11/23.
//

#pragma once

#include "sfml.h"
#include "std.h"
#include "Components.h"
#include "Rect.h"
#include "DrawableComponent.h"
#include "toSFML.h"
#include "Transform.h"
#include "Vector2.h"

/**
 * @brief Sprite class: Sprite is a class that represents the rendering properties of a Component.
 *
 * The Sprite class manages the graphical representation of a Component using SFML.
 */
class Sprite : public DrawableComponent, public toSFML, public Transform {
private:
    sf::Sprite sprite; ///< SFML Sprite for rendering.
    sf::Texture texture; ///< SFML Texture for the sprite.
    std::function<void()> deferredSprite; ///< Deferred sprite.

    std::vector<Rect<int>> frames; /// < Vector of all frames for animation.
    sf::Time timeSinceLastFrame; /// < The time since the last frames was draw.
    sf::Time frameDuration; /// < The duration of draw a frame.
    int currentFrame; /// < The current frame.
    bool animation; /// < Sprite is animated.

    int bit = 1; ///< Bit of the Sprite.
    void doAnimation(sf::Time deltaTime); /// < Doing the animation.
public:
    /// @brief Default Sprite constructor.
    /// @param void
    /// @return void
    Sprite() = default;

    /// @brief Sprite constructor with an existing texture path.
    /// @param texturePath: Path to the texture file for the sprite.
    /// @return void
    Sprite(const std::string& texturePath) {
        if (texture.loadFromFile(texturePath)) {
            sprite.setTexture(texture);
        } else {
            std::cerr << "Error: Texture not found" << std::endl;
        }
    }

    /// @brief Sprite destructor.
    /// @param void
    /// @return void
    ~Sprite() override = default;

    /// @brief init(): Initialize the Sprite.
    /// @param void
    /// @return bool: True if the Sprite is initialized, false otherwise.
    bool initSprite() const {return true;}

    /// @brief getBit(): Get the bit of the Sprite.
    /// @param void
    /// @return int: The bit of the Sprite.
    int getBit() const {return bit;}

    /// @brief draw(): Draw the Sprite.
    /// @param window: SFML RenderWindow where the Sprite will be drawn.
    /// @return void
    void draw(sf::RenderWindow& window) const override;

    void update(sf::Time deltaTime) override;

    /// @brief createSprite(): Create the SFML Sprite with a texture path for rendering.
    /// @param texturePath: Path to the texture file for the sprite.
    /// @return void
    void createSprite(const std::string& texturePath);

    /// @brief createSprite(): Create the SFML Sprite with an existing texture for rendering.
    /// @param existingTexture: SFML Texture for the sprite
    /// @return void
    void createSprite(const sf::Texture& existingTexture);

    /// @brief createSprite(): Create the SFML Sprite with the component's texture for rendering.
    /// @param void
    /// @return void
    void createSprite();

    /// @brief getSprite(): Get the SFML Sprite for rendering.
    /// @param void
    /// @return sf::Sprite: SFML Sprite for rendering
    [[nodiscard]] sf::Sprite getSprite() const;

    /// @brief getTexture(): Get the SFML Texture for the sprite.
    /// @param void
    /// @return sf::Texture: SFML Texture for the sprite
    [[nodiscard]] sf::Texture getTexture() const;

    /// @brief isTextureLoaded(): Check if the texture is loaded.
    /// @param void
    /// @return bool: True if the texture is loaded, false otherwise.
    bool isTextureLoaded() const {return texture.getSize().x != 0 && texture.getSize().y != 0;}

    /// @brief setSprite(): Set the SFML Sprite with an existing one for rendering.
    /// @param sprite: SFML Sprite for rendering
    /// @return void
    void setSprite(const sf::Sprite& sprite);

    /// @brief setSprite(): Set the SFML Sprite with a map of string and textures, a texture name and a map of string and vector of floats.
    /// @param mapTexture: Map of string and textures.
    /// @param nameTexture: Name of the texture.
    /// @param mapTransform: Map of string and vector of floats.
    /// @return void
    void setSprite(std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture, std::string nameTexture,
                   bool animate = false, std::vector<Rect<int>> newFrames = std::vector<Rect<int>>(), int durationOfFrame = 100);

<<<<<<< HEAD
    /// @brief setTransformSprite(): Set the sprite transform with new value and set the value on the Transform component.
    /// @param newPosition: The new Vector2<float> position.
    /// @param newRotation: The new float rotation.
    /// @param newScale: The new Vector2<float> scale.
    /// @return void
    void setTransformSprite(Vector2<float> newPosition, float newRotation, Vector2<float> newScale);

    /// @brief setTransformSprite(): Set the transform of the sprite based on the Transform component value.
    /// @param void
    /// @return void
    void setTransformSprite();

    /// @brief setPosition(): Set the position of the sprite with new value.
    /// @param newPosition: The new Vector2<float> position.
    /// @return void
    void setPosition(Vector2<float> newPosition);

    /// @brief setPosition(): Set the position of the sprite based on the Transform component value.
    /// @param void
    /// @return void
    void setPosition();

    /// @brief setRotation(): Set the rotation of the sprite with new value.
    /// @param newRotation: The new float rotation.
    /// @return void
    void setRotation(float newRotation);

    /// @brief setRotation(): Set the rotation of the sprite based on the Transform component value.
    /// @param void
    /// @return void
    void setRotation();

    /// @brief setScale(): Set the the scale of the sprite with new value.
    /// @param newScale: The new Vector2<float> scale.
    /// @return void
    void setScale(Vector2<float> newScale);

    /// @brief setScale(): Set the scale of the sprite based on the Transform component value.
    /// @param void
    /// @return void
=======
    void setTransformSprite(Vector2<float> newPosition, float newRotation, Vector2<float> newScale);

    void setTransformSprite();

    void setPosition(Vector2<float> newPosition);

    void setPosition();

    void setRotation(float newRotation);

    void setRotation();

    void setScale(Vector2<float> newScale);

>>>>>>> 8bf355f ([m] Engine:)
    void setScale();

    /// @brief setDeferredSprite(): Set the deferred sprite.
    /// @param setter: Function that will set the sprite.
    /// @return void
    void setDeferredSprite(std::function<void()> setter);

    /// @brief applyDeferredSprite(): Apply the deferred sprite.
    /// @param void
    /// @return void
    void applyDeferredSprite();

    /// @brief setTexture(): Set the texture with an existing one for the sprite.
    /// @param existingTexture: SFML Texture for the sprite
    /// @return void
    void setTexture(const sf::Texture& existingTexture);

    Rect<float> getBounds() const;
};

