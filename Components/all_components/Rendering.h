//
// Created by thibaultcampagne on 30/11/23.
//

#ifndef R_TYPE_RENDERING_H
#define R_TYPE_RENDERING_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../Components.h"

/**
 * @brief Rendering class: Rendering is a class that represents the rendering properties of a Component.
 *
 * The Rendering class manages the graphical representation of a Component using SFML.
 */
class Rendering : public Components {
private:
    sf::Sprite sprite; ///< SFML Sprite for rendering.
    sf::Texture texture; ///< SFML Texture for the sprite.

public:
    /// @brief Default Rendering constructor.
    /// @param void
    /// @return void
    Rendering() = default;

    /// @brief Rendering constructor with an existing texture path.
    /// @param texturePath: Path to the texture file for the sprite.
    /// @return void
    explicit Rendering(const std::string& texturePath) {
        if (texture.loadFromFile(texturePath)) {
            sprite.setTexture(texture);
        } else {
            std::cerr << "Error: Texture not found" << std::endl;
        }
    }

    /// @brief Rendering destructor.
    /// @param void
    /// @return void
    ~Rendering() override = default;

    /// @brief createSprite(): Create the SFML Sprite with a texture path for rendering.
    /// @param texturePath: Path to the texture file for the sprite.
    /// @return bool: True if the sprite has been created, false otherwise
    bool createSprite(const std::string& texturePath);

    /// @brief createSprite(): Create the SFML Sprite with an existing texture for rendering.
    /// @param existingTexture: SFML Texture for the sprite
    /// @return bool: True if the sprite has been created, false otherwise
    bool createSprite(const sf::Texture& existingTexture);

    /// @brief createSprite(): Create the SFML Sprite with the component's texture for rendering.
    /// @param bool
    /// @return bool: True if the sprite has been created, false otherwise
    bool createSprite();

    /// @brief getSprite(): Get the SFML Sprite for rendering.
    /// @param void
    /// @return sf::Sprite: SFML Sprite for rendering
    [[nodiscard]] sf::Sprite getSprite() const;

    /// @brief getTexture(): Get the SFML Texture for the sprite.
    /// @param void
    /// @return sf::Texture: SFML Texture for the sprite
    [[nodiscard]] sf::Texture getTexture() const;

    /// @brief setSprite(): Set the SFML Sprite with an existing one for rendering.
    /// @param sprite: SFML Sprite for rendering
    /// @return bool: True if the sprite has been set, false otherwise
    bool setSprite(const sf::Sprite& sprite);

    /// @brief setTexture(): Set the texture with a texture path for the sprite. Automatically create the sprite.
    /// @param texturePath: Path to the texture file for the sprite.
    /// @return bool: True if the texture has been set, false otherwise
    bool setTexture(const std::string& texturePath);

    /// @brief setTexture(): Set the texture with an existing one for the sprite. Automatically create the sprite.
    /// @param existingTexture: SFML Texture for the sprite
    /// @return bool: True if the texture has been set, false otherwise
    bool setTexture(const sf::Texture& existingTexture);
};

#endif //R_TYPE_RENDERING_H
