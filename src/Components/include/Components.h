//
// Created by thibaultcampagne on 29/11/23.
//

#pragma once

#include "std.h"
#include "sfml.h"

class Components {
public:
    Components() = default;
    virtual ~Components() = default;

    virtual bool init() {return true;}
    virtual void update(sf::Time timeDelta) = 0;
};

