//
// Created by piotr on 05.11.16.
//

#include "../../include/crazygoat/Parsers/QueryParser.h"
#include "../../include/crazygoat/Helpers/StringHelper.h"
#include "../../include/crazygoat/Helpers/UrlHelper.h"
#include "../../include/crazygoat/Array/ArrayHelper.h"

void QueryParser::parse() {
    auto pairs = StringHelper::split(this->message, "&", true);
    for (auto keyValue: pairs) {

        auto pos_eq = keyValue.find('=');
        if (pos_eq != std::string::npos) {

            auto value = keyValue.substr(pos_eq + 1);
            auto path = UrlHelper::array_elements(keyValue.substr(0, pos_eq));

            this->params = ArrayHelper::setByPath(this->params, path, value);
        }
    }
}

Array QueryParser::getAllParams() {
    if (!this->parsed) this->parse();
    return this->params;
}

std::string QueryParser::getParameter(std::string name, std::string value) {
    if (!this->parsed) this->parse();
    return nullptr;
}

std::string QueryParser::hasParameter(std::string name) {
    if (!this->parsed) this->parse();
    return nullptr;
}

bool QueryParser::removeParameter(std::string name) {
    if (!this->parsed) this->parse();
    return false;
}

bool QueryParser::setParameter(std::string name) {
    if (!this->parsed) this->parse();
    return false;
}
