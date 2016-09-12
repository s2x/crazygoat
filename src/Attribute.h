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
    Attribute(std::string value, std::string name = "");
    operator std::string() const;
};


#endif //CRAZYGOAT_ATTRIBUTE_H
