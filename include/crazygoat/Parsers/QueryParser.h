//
// Created by piotr on 05.11.16.
//

#ifndef LIBCRAZYGOAT_QUERYPARSER_H
#define LIBCRAZYGOAT_QUERYPARSER_H

#include <fcgiapp.h>
#include "../Array/Array.h"
#include "HttpParserAbstract.h"

class QueryParser : public HttpParserAbstract {
protected:
    std::string separator = "&";
    bool parsed = false;
public:
    QueryParser(std::string message, std::string separator = "&"):
            HttpParserAbstract(message),
            separator(separator),
            parsed(false) {};
    void parse();

    virtual Array getAllParams() override;

    virtual std::string getParameter(std::string name, std::string value) override;

    virtual std::string hasParameter(std::string name) override;

    virtual bool removeParameter(std::string name) override;

    virtual bool setParameter(std::string name) override;
};


#endif //LIBCRAZYGOAT_QUERYPARSER_H
