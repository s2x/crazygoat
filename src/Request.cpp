//
// Created by piotr on 12.09.16.
//

#include "Request.h"

Request::Request(FCGX_Request request) {
    this->attributes = new AttributesList(request);
    this->request = request;
}

Request::~Request() {
    delete this->attributes;
}

