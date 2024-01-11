//
// Created by thibaultcampagne on 30/11/23.
//

#pragma once

#include "std.h"
#include "Components.h"
#include "sfml.h"
#include "Vector2.h"

/**
 * @brief Transform class: Transform is a class that represents the transform of a Component.
 *
 * The Transform class manages the position, rotation and scale of a Component.
 */
class Transform : public Components {
private:
    struct TransformStruct {
        Vector2<float> position; ///< Position vector of the component (x, y).
        float rotation; ///< Rotation vector of the component (x, y).
        Vector2<float> scale; ///< Scale vector of the component (x, y).
    };
    TransformStruct  transform;
    int bit = 0; ///< Bitmask to track transformation properties.
public:
    /// @brief Default Transform constructor
    /// @param void
    /// @return void
    Transform() : transform{Vector2<float>(0.0f, 0.0f), 0.0f, Vector2<float>(1.0f, 1.0f)} {}

//    Transform(Vector2<float> newPosition, float newRotation, Vector2<float> newScale) {
//        transform.position = newPosition;
//        transform.rotation = newRotation;
//        transform.scale = newScale;
//    }

    bool init() const {return true;}

    /// @brief Transform destructor
    /// @param void
    /// @return void
    ~Transform() override = default;

    void update(sf::Time deltaTime) override;

    /// @brief getBit(): Get the bitmask of the component
    /// @param void
    /// @return int: bitmask of the component
    [[nodiscard]] int getBit() const;

    /// @brief getPositionVector(): Get the position vector of the component;
    /// @param void
    /// @return std::vector<float>: position vector of the component
    Vector2<float> getPosition() const {return transform.position;}

    /// @brief getRotationVector(): Get the rotation vector of the component;
    /// @param void
    /// @return std::vector<float>: rotation vector of the component
    float getRotation() const {return transform.rotation;}

    /// @brief getScaleVector(): Get the scale vector of the component;
    /// @param void
    /// @return std::vector<float>: scale vector of the component
    Vector2<float> getScale() const {return transform.scale;}

    TransformStruct getTransformStruct() const {return transform;}

    void setTransform(Vector2<float> newPosition, float newRotation, Vector2<float> newScale);

    void setPosition(Vector2<float> newPosition);

    void setRotation(float newRotation);

    void setScale(Vector2<float> newScale);
};

