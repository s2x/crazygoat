//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_ATTRIBUTES_H
#define CRAZYGOAT_ATTRIBUTES_H


#include <map>
#include <vector>
#include "Attribute.h"
#include <iostream>

class AttributesList {
private:
    std::map<std::string, std::vector<Attribute> > attributes;
public:
    void setAttribute(std::string name, Attribute attribute);
    operator std::string() const;
};


#endif //CRAZYGOAT_ATTRIBUTES_H
