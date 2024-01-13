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
#include "ITransform.h"

/**
 * @brief Sprite class: Sprite is a class that represents the rendering properties of a Component.
 *
 * The Sprite class manages the graphical representation of a Component using SFML.
 */

class Sprite : public DrawableComponent, public toSFML, public Transform, public ITransform {
private:
    sf::Sprite sprite;                    /// < SFML Sprite for rendering.
    std::function<void()> deferredSprite; /// < Deferred function for sprite.

    Transform* transform; /// < Reference of component Transform.

    std::vector<Rect<int>> frames; /// < Vector of all frames for animation.
    sf::Time timeSinceLastFrame;   /// < The time since the last frames was draw.
    sf::Time frameDuration;        /// < The duration of draw a frame.
    unsigned long currentFrame{};              /// < The current frame.
    bool animation{};                /// < Sprite is animated.

    int bit = 1;                          ///< Bit of the Sprite.
    void doAnimation(sf::Time deltaTime); /// < Doing the animation.
public:
    /**
     * @brief Default Sprite constructor.
     *
     * Set the default value to "Default" and initialize the transform reference to null.
     */
    Sprite() : transform(nullptr) {}

    /**
     * @brief Default override Sprite destructor.
     *
     * Set the default value to "Default".
     */
    ~Sprite() override = default;

    /**
     * @brief getTransform(): Get the reference to the component Transform.
     * @return Transform*: Reference of Transform
     */
    Transform* getTransform() override;

    /**
     * @brief init(): Initialize the component.
     * @return bool: true if the component is initialized, false otherwise
     */
    bool init() override;

    /**
     * @brief getBit(): Get the bit of the Music.
     * @return int: The bit of the Music.
     */
    int getBit() override;

    /**
     * @brief draw(): Draw the Sprite.
     * @param window: SFML RenderWindow where the Sprite will be drawn.
     */
    void draw(sf::RenderWindow &window) const override;

    /**
     * @brief update(sf::Time): Update the component Music
     * @param timeDelta: sf::Time of the game.
     */
    void update(sf::Time deltaTime) override;

    /**
     * @brief getSprite(): Get the SFML Sprite for rendering.
     * @return sf::Sprite: SFML Sprite for rendering
     */
    sf::Sprite getSprite() const;

    /**
     * @brief setSprite(sf::Sprite&): Set the SFML Sprite with an existing one for rendering.
     * @param sprite: SFML Sprite for rendering
     */
    void setSprite(const sf::Sprite &sprite);

    /**
     * @brief Sets the sprite of the component.
     *
     * This function sets the sprite of the component using the provided texture map and texture name.
     * Optionally, it can enable animation by providing a vector of frames and the duration of each frame.
     *
     * @param mapTexture A map of texture names and their corresponding shared pointers to sf::Texture objects.
     * @param nameTexture The name of the texture to set as the sprite.
     * @param animate Flag indicating whether to enable animation or not. Default is false.
     * @param newFrames A vector of frames to use for animation. Default is an empty vector.
     * @param durationOfFrame The duration of each frame in milliseconds. Default is 100 milliseconds.
     * @return void
     */
    void setSprite(std::map<std::string, std::shared_ptr<sf::Texture>> mapTexture, const std::string& nameTexture,
                   bool animate = false, const std::vector<Rect<int>>& newFrames = std::vector<Rect<int>>(), int durationOfFrame = 100);

    /**
     * @brief setDeferredSprite(std::function<void()>): Set the deferred sprite.
     * @param setter: Function that will set the sprite.
     */
    void setDeferredSprite(std::function<void()> setter);

    /**
     * @brief applyDeferredSprite(): Apply the deferred sprite.
     */
    void applyDeferredSprite();

    /**
     * @brief setTransform(Transform&): Set the reference of the Transform component.
     * @param newTransform: Reference of Transform.
     */
    void setTransform(Transform& newTransform);
};
