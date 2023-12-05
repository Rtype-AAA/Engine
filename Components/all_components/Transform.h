//
// Created by thibaultcampagne on 30/11/23.
//

#ifndef R_TYPE_TRANSFORM_H
#define R_TYPE_TRANSFORM_H


#include <limits>
#include <vector>
#include "../Components.h"

class Transform : public Components{
private:
     float position_x;
     float position_y;
     float rotation_x;
     float rotation_y;
     float scale_x;
     float scale_y;
     static float inf;
     int bit = 0;
public:
    explicit Transform(float px = 0, float py = 0,
              float rx = 0, float ry = 0,
              float sx = 1, float sy = 1) {
        position_x = px;
        position_y = py;
        rotation_x = rx;
        rotation_y = ry;
        scale_x = sx;
        scale_y = sy;
        //inf = std::numeric_limits<float>::infinity();
    }
    ~Transform() override = default;

    [[nodiscard]] int getBit() const;
    [[nodiscard]] float getPositionX() const;
    [[nodiscard]] float getPositionY() const;
    [[nodiscard]] float getRotationX() const;
    [[nodiscard]] float getRotationY() const;
    [[nodiscard]] float getScaleX() const;
    [[nodiscard]] float getScaleY() const;

    inline void setTransform(float px = inf, float py = inf,
                             float rx = inf, float ry = inf,
                             float sx = inf, float sy = inf);

};


#endif //R_TYPE_TRANSFORM_H
