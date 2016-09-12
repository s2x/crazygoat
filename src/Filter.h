//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_ACTION_H
#define CRAZYGOAT_ACTION_H

#include "Response.h"
#include "Request.h"

class Filter {
protected:
    Filter *next;
    Response processNext(Request request, Response response);
public:
    void setNext(Filter *next);
    virtual Response invoke(Request request, Response response) {};
};


#endif //CRAZYGOAT_ACTION_H
