//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_REQUEST_H
#define CRAZYGOAT_REQUEST_H


#include <fcgiapp.h>
#include "../include/crazygoat/AttributesList.h"

class Request {
protected:
    AttributesList *attributes;
    FCGX_Request request;
public:
    explicit Request(FCGX_Request request);
    Request(const Request& a): attributes(new AttributesList(*a.attributes)) {};
    ~Request();
};

#endif //CRAZYGOAT_REQUEST_H
