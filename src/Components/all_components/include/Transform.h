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

    /// @brief init(): Initialize the component
    /// @param void
    /// @return bool: true if the component is initialized, false otherwise
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

    /// @brief getTransformStruct(): Get the the transform of the component;
    /// @param void
    /// @return TransformStruct: struct of the Transform.
    TransformStruct getTransformStruct() const {return transform;}

    /// @brief setTransformStruct(): Set the transform of the component;
    /// @param newPosition : the new Vector2<float> position.
    /// @param newRotation : the new float rotation.
    /// @param newScale : the new Vector2<float> scale.
    /// @return void
    void setTransform(Vector2<float> newPosition, float newRotation, Vector2<float> newScale);

    /// @brief setTransformPosition(): Set the transform position of the component;
    /// @param newPosition : the new Vector2<float> position.
    /// @return void
    void setTransformPosition(Vector2<float> newPosition);

    /// @brief setTransformRotation(): Set the transform rotation of the component;
    /// @param newRotation : the new float rotation.
    /// @return void
    void setTransformRotation(float newRotation);

    /// @brief setTransformScale(): Set the transform scale of the component;
    /// @param newScale : the new Vector2<float> scale.
    /// @return void
    void setTransformScale(Vector2<float> newScale);
};

