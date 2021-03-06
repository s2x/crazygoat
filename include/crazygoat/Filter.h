//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_ACTION_H
#define CRAZYGOAT_ACTION_H

#include "../../src/Response.h"
#include "../../src/Request.h"

class Filter {
protected:
    Filter *next;
public:
    Filter();
    void setNext(Filter *next);
    virtual Response invoke(Request request, Response response) {};
};


#endif //CRAZYGOAT_ACTION_H
