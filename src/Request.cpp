//
// Created by piotr on 12.09.16.
//

#include "Request.h"

Request::Request(FCGX_Request request) {
    this->request = request;
    this->attributes = new AttributesList(request);
    this->queryParams = new QueryParser(this->getEnvParameter("QUERY_STRING"));
}

Request::~Request() {
    delete this->attributes;
}

std::string Request::getEnvParameter(std::string name, std::string default_value) {
    char *tmp = FCGX_GetParam(name.c_str(), this->request.envp);
    return (tmp != NULL) ? tmp : default_value;
}

bool Request::hasEnvParameter(std::string name) {
    return (FCGX_GetParam(name.c_str(), this->request.envp) != NULL);
}
