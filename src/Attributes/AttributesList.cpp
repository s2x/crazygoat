//
// Created by piotr on 12.09.16.
//

#include "../../include/crazygoat/AttributesList.h"

AttributesList::operator std::string() {
    std::string headers;
    for (auto& header: this->attributes) {
        headers += header.first + ":" + header.second.front().toString() +"\r\n";
    }
    return headers;
}

void AttributesList::setAttribute(std::string name, Attribute attribute) {
    //check if exists
    if (this->attributes.find(name)!=this->attributes.end()) {
        //clear
        this->attributes[name].clear();
    }
    this->attributes[name].push_back(attribute);
}

AttributesList::AttributesList() {
    this->attributes.clear();
}

AttributesList::AttributesList(FCGX_Request request) {
    this->attributes.clear();
}

bool AttributesList::hasAttribute(std::string name) {
    return !(this->attributes.find(name) == this->attributes.end());
}

std::string AttributesList::getAttribute(std::string name) {
    std::string str = "";
    if (this->hasAttribute(name)) {
        auto item = this->attributes[name];
        auto size = item.size();
        auto iter = 1;

        for (auto &value : item) {
            str += value.toString();
            if (iter < size) str += ";";
            iter++;
        }
    }

    return str;
}











