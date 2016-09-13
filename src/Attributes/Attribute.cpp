//
// Created by piotr on 12.09.16.
//

#include "Attribute.h"

Attribute::Attribute(std::string value, std::string name) {
    this->name = name;
    this->value = value;
}

std::string Attribute::toString() {
    if (this->name.length()) {
        return this->name + "=" + this->value;
    }
    return this->value;
}

