//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_ATTRIBUTE_H
#define CRAZYGOAT_ATTRIBUTE_H

#include <iostream>

class Attribute {
protected:
    std::string name;
    std::string value;
public:
    Attribute(std::string value, std::string name = ""):name(name), value(value) {};
    std::string toString();
};


#endif //CRAZYGOAT_ATTRIBUTE_H
