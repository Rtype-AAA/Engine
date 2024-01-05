//
// Created by thibaultcampagne on 30/11/23.
//

#pragma once

#include "sfml.h"
#include "std.h"
#include "Components.h"
#include "DrawableComponent.h"

/**
 * @brief Sprite class: Sprite is a class that represents the rendering properties of a Component.
 *
 * The Sprite class manages the graphical representation of a Component using SFML.
 */
class Sprite : public Components, public DrawableComponent {
private:
    sf::Sprite sprite; ///< SFML Sprite for rendering.
    sf::Texture texture; ///< SFML Texture for the sprite.
    std::function<void()> deferredSprite; ///< Deferred sprite.
    int bit = 1; ///< Bit of the Sprite.
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
    void setSprite(std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture, std::string nameTexture, std::map<std::string, std::vector<float>>& mapTransform);

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
};

