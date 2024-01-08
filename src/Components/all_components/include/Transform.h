//
// Created by thibaultcampagne on 30/11/23.
//

#pragma once

#include "std.h"
#include "Components.h"

/**
 * @brief Transform class: Transform is a class that represents the transform of a Component.
 *
 * The Transform class manages the position, rotation and scale of a Component.
 */
class Transform : public Components {
private:
    std::vector<float> position = {0.0f, 0.0f}; ///< Position vector of the component (x, y).
    std::vector<float> rotation = {0.0f, 0.0f}; ///< Rotation vector of the component (x, y).
    std::vector<float> scale = {1.0f, 1.0f}; ///< Scale vector of the component (x, y).
    int bit = 0; ///< Bitmask to track transformation properties.
public:
    /// @brief Default Transform constructor
    /// @param void
    /// @return void
    Transform() = default;

    /// @brief init(): Initialize the component
    /// @param void
    /// @return bool: true if the component is initialized, false otherwise
    bool init() const {return true;}

    /// @brief Transform constructor
    /// @param mapTransform: Map containing transformation properties (std::string, std::vector<float>).
    /// @return void
    Transform(std::map<std::string, std::vector<float>>& mapTransform) {
        for(const auto& element : mapTransform) {
            if ((element.first == "Position" || element.first == "position") && element.second.size() == 2) {
                position = element.second;
            }
            if ((element.first == "Rotation" || element.first == "rotation") && element.second.size() == 2) {
                rotation = element.second;
            }
            if ((element.first == "Scale" || element.first == "scale") && element.second.size() == 2) {
                scale = element.second;
            }
        }
    }

    /// @brief Transform destructor
    /// @param void
    /// @return void
    ~Transform() override = default;

    /// @brief getBit(): Get the bitmask of the component
    /// @param void
    /// @return int: bitmask of the component
    [[nodiscard]] int getBit() const;

    /// @brief getPositionVector(): Get the position vector of the component;
    /// @param void
    /// @return std::vector<float>: position vector of the component
    [[nodiscard]] std::vector<float> getPositionVector() const;

    /// @brief getRotationVector(): Get the rotation vector of the component;
    /// @param void
    /// @return std::vector<float>: rotation vector of the component
    [[nodiscard]] std::vector<float> getRotationVector() const;

    /// @brief getScaleVector(): Get the scale vector of the component;
    /// @param void
    /// @return std::vector<float>: scale vector of the component
    [[nodiscard]] std::vector<float> getScaleVector() const;

    /// @brief setTransform(): Set the transformation properties of the component
    /// @param mapTransform: Map containing transformation properties (std::string, std::vector<float>).
    /// @return void
    void setTransform(const std::map<std::string, std::vector<float>>& mapTransform);
};

