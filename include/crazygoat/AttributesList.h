//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_ATTRIBUTES_H
#define CRAZYGOAT_ATTRIBUTES_H


#include <map>
#include <vector>
#include "Attribute.h"
#include <iostream>
#include <fcgiapp.h>

class AttributesList {
private:
    std::map<std::string, std::vector<Attribute> > attributes;
public:
    AttributesList();
    AttributesList(FCGX_Request request);
    void setAttribute(std::string name, Attribute attribute);
    operator std::string();
};


#endif //CRAZYGOAT_ATTRIBUTES_H
