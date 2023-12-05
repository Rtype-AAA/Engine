//
// Created by thibaultcampagne on 30/11/23.
//

#ifndef R_TYPE_TRANSFORM_H
#define R_TYPE_TRANSFORM_H


#include <limits>
#include <vector>
#include <map>
#include <algorithm>
#include "../Components.h"

class Transform : public Components{
private:
    std::vector<float> position = {0.0f, 0.0f};
    std::vector<float> rotation = {0.0f, 0.0f};
    std::vector<float> scale = {1.0f, 1.0f};
     int bit = 0;
public:
    Transform() = default;
    explicit Transform(const std::map<std::string, std::vector<float>>& mapTransform) {
        for(const auto& element : mapTransform) {
            if ((element.first == "Position" or element.first == "position") and element.second.size() == 2) {
                position = element.second;
            }
            if ((element.first == "Rotation" or element.first == "rotation") and element.second.size() == 2) {
                rotation = element.second;
            }
            if ((element.first == "Scale" or element.first == "scale") and element.second.size() == 2) {
                scale = element.second;
            }
        }
    }
    ~Transform() override = default;

    [[nodiscard]] int getBit() const;
    [[nodiscard]] std::vector<float> getPositionVector() const;
    [[nodiscard]] std::vector<float> getRotationVector() const;
    [[nodiscard]] std::vector<float> getScaleVector() const;

    void setTransform(const std::map<std::string, std::vector<float>>& mapTransform);

};


#endif //R_TYPE_TRANSFORM_H
