//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_REQUEST_H
#define CRAZYGOAT_REQUEST_H


#include <fcgiapp.h>
#include "../include/crazygoat/AttributesList.h"
#include "../include/crazygoat/Array/Array.h"
#include "../include/crazygoat/Parsers/QueryParser.h"

class Request {
protected:
    QueryParser *queryParams;
    AttributesList *attributes;
    FCGX_Request request;
public:
    explicit Request(FCGX_Request request);
    Request(const Request& a): attributes(new AttributesList(*a.attributes)) {};
    ~Request();

    std::string getEnvParameter(std::string name, std::string default_value = "");
    bool hasEnvParameter(std::string name);
};

#endif //CRAZYGOAT_REQUEST_H
