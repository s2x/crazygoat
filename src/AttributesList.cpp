//
// Created by piotr on 12.09.16.
//

#include "AttributesList.h"

AttributesList::operator std::string() const {
    return "dupa";
}

void AttributesList::setAttribute(std::string name, Attribute attribute) {
    //check if exists
    if (this->attributes.find(name)!=this->attributes.end()) {
        //clear
        this->attributes[name].clear();
    }
    this->attributes[name].push_back(attribute);
}



