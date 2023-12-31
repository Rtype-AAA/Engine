//
// Created by thibaultcampagne on 30/11/23.
//

#ifndef R_TYPE_SPRITE_H
#define R_TYPE_SPRITE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <functional>
#include "../Components.h"
#include "../DrawableComponent.h"

/**
 * @brief Sprite class: Sprite is a class that represents the rendering properties of a Component.
 *
 * The Sprite class manages the graphical representation of a Component using SFML.
 */
class Sprite : public Components, public DrawableComponent {
private:
    sf::Sprite sprite; ///< SFML Sprite for rendering.
    sf::Texture texture; ///< SFML Texture for the sprite.
    std::function<void()> deferredSprite;
    int bit = 1;
public:
    /// @brief Default Sprite constructor.
    /// @param void
    /// @return void
    Sprite() = default;

    /// @brief Sprite constructor with an existing texture path.
    /// @param texturePath: Path to the texture file for the sprite.
    /// @return void
    explicit Sprite(const std::string& texturePath) {
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

    bool init() const {return true;}

    int getBit() const {return bit;}

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

    bool isTextureLoaded() const {return texture.getSize().x != 0 && texture.getSize().y != 0;}

    /// @brief setSprite(): Set the SFML Sprite with an existing one for rendering.
    /// @param sprite: SFML Sprite for rendering
    /// @return void
    void setSprite(const sf::Sprite& sprite);

    /// @brief setTexture(): Set the texture with a texture path for the sprite.
    /// @param texturePath: Path to the texture file for the sprite.
    /// @return void
    void setSprite(std::map<std::string, sf::Texture> mapTexture, std::string nameTexture);

    void setDeferredSprite(std::function<void()> setter);

    void applyDeferredSprite();

    /// @brief setTexture(): Set the texture with an existing one for the sprite.
    /// @param existingTexture: SFML Texture for the sprite
    /// @return void
    void setTexture(const sf::Texture& existingTexture);
};

#endif //R_TYPE_SPRITE_H
