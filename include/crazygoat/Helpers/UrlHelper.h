//
// Created by piotr on 05.11.16.
//

#ifndef LIBCRAZYGOAT_URLHELPER_H
#define LIBCRAZYGOAT_URLHELPER_H

#include <iostream>

class UrlHelper {
public:
    static std::string url_encode(const std::string &value);
    static std::string url_decode(const std::string &value);

    static std::vector<std::string> array_elements(const std::string &s);
};


#endif //LIBCRAZYGOAT_URLHELPER_H
