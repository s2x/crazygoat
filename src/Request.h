//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_REQUEST_H
#define CRAZYGOAT_REQUEST_H


#include <fcgiapp.h>
#include "Attributes/AttributesList.h"

class Request {
protected:
    AttributesList *attributes;
    FCGX_Request request;
public:
    Request();
    Request(FCGX_Request request);
};


#endif //CRAZYGOAT_REQUEST_H
