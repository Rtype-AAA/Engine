//
// Created by thibaultcampagne on 13/01/24.
//

#pragma once

#include "Transform.h"

/**
 * @brief ITransform class: ITransform is a class that represents an interface of the Component Transform
 *
 * The ITransform interface give to components which need to have a reference to Transform
 */

class ITransform {
public:
    /**
     * @brief Default Virtual ITransform destructor.
     *
     * Set the default value to "Default".
     */
    virtual ~ITransform() = default;

    /**
     * @brief getTransform(): Get the reference of the component Transform of the same Entity
     *
     * Virtual function which get the reference of the Transform component from the same Entity when
     * a component need to use Transform. If Transform don't exist getTransform() return nullptr.
     *
     * @return Transform*: The reference of Transform or nullptr.
     */
    [[nodiscard]] virtual Transform * getTransform() = 0;
};