//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_RESPONSE_H
#define CRAZYGOAT_RESPONSE_H

#include <iostream>
#include "Attributes/AttributesList.h"

class Response {
protected:
    std::string content;
    AttributesList attributes;
public:
    Response();
    std::string getContent();
    std::string getHeaders();
    void setContent(std::string content);
};


#endif //CRAZYGOAT_RESPONSE_H
