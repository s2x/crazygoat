//
// Created by piotr on 12.09.16.
//

#include "../../include/crazygoat/Attribute.h"

std::string Attribute::toString() {
    if (this->name.length()) {
        return this->name + "=" + this->value;
    }
    return this->value;
}

