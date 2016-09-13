//
// Created by piotr on 12.09.16.
//

#include "../../include/crazygoat/Filter.h"

void Filter::setNext(Filter *next) {
    this->next = next;
}

Filter::Filter() {
    this->next = nullptr;
}






