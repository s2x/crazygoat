//
// Created by piotr on 05.11.16.
//

#ifndef LIBCRAZYGOAT_HTTPPARSERINTERFACE_H
#define LIBCRAZYGOAT_HTTPPARSERINTERFACE_H


#include "../Array/Array.h"

class HttpParserAbstract {
protected:
    std::string message;
    Array params;
public:
    explicit HttpParserAbstract(std::string message): message(message) {};
    virtual ~HttpParserAbstract() {};

    virtual Array getAllParams() = 0;
    virtual std::string getParameter(std::string name, std::string value = "") = 0;
    virtual std::string hasParameter(std::string name) = 0;
    virtual bool removeParameter(std::string name) = 0;
    virtual bool setParameter(std::string name) = 0;
};


#endif //LIBCRAZYGOAT_HTTPPARSERINTERFACE_H
