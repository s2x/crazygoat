//
// Created by piotr on 12.09.16.
//

#include <sstream>
#include "Response.h"

std::string Response::getContent() {
    return this->content;
}

std::string Response::getHeaders() {
    return this->attributes;
}

Response::Response() {
    this->content = "";
    this->attributes.setAttribute("Content-type", Attribute("text/html"));
}

void Response::setContent(std::string content) {
    this->content = content;
    this->attributes.setAttribute(
            "Content-length",
            Attribute(std::to_string(this->content.length()))
    );
}

std::string Response::getHeader(std::string name) {
    return this->attributes.getAttribute(name);
}

bool Response::hasHeader(std::string name) {
    return this->attributes.hasAttribute(name);
}











