//
// Created by piotr on 05.11.16.
//

#include "../../include/crazygoat/Helpers/StringHelper.h"

#include <algorithm>

std::vector<std::string> StringHelper::split(const std::string& s, const std::string& delimiter, const bool keep_empty) {
    std::vector<std::string> result;
    if (delimiter.empty()) {
        result.push_back(s);
        return result;
    }
    std::string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = std::search(substart, s.end(), delimiter.begin(), delimiter.end());
        std::string temp(substart, subend);
        if (keep_empty || !temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delimiter.size();
    }
    return result;
}