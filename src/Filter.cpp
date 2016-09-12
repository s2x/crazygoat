//
// Created by piotr on 12.09.16.
//

#include "Filter.h"

void Filter::setNext(Filter *next) {
    this->next = next;
}

Response Filter::processNext(Request request, Response response) {
    return Response();
}




