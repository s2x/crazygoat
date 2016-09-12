//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_REQUEST_H
#define CRAZYGOAT_REQUEST_H


#include <fcgiapp.h>

class Request {
public:
    Request(FCGX_Request request);
};


#endif //CRAZYGOAT_REQUEST_H
