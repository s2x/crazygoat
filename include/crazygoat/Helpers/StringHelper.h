//
// Created by piotr on 05.11.16.
//

#ifndef LIBCRAZYGOAT_STRINGHELPER_H
#define LIBCRAZYGOAT_STRINGHELPER_H


#include <vector>
#include <iostream>

class StringHelper {
public:
    static std::vector<std::string> split(const std::string& s, const std::string& delimiter, const bool keep_empty);
};


#endif //LIBCRAZYGOAT_STRINGHELPER_H
