//
// Created by piotr on 05.11.16.
//

#include <cctype>
#include <sstream>
#include <vector>
#include <pcre.h>
#include "../../include/crazygoat/Helpers/UrlHelper.h"

const std::string array_pattern = "\\[[^\\]]*\\]";
pcre *re;

const char HEX2DEC[256] =
        {
                /*       0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F */
                /* 0 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* 1 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* 2 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* 3 */  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,

                /* 4 */ -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* 5 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* 6 */ -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* 7 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,

                /* 8 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* 9 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* A */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* B */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,

                /* C */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* D */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* E */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                /* F */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
        };


// Only alphanum is safe.
const char SAFE[256] =
        {
                /*      0 1 2 3  4 5 6 7  8 9 A B  C D E F */
                /* 0 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                /* 1 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                /* 2 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                /* 3 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,

                /* 4 */ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                /* 5 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
                /* 6 */ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                /* 7 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,

                /* 8 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                /* 9 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                /* A */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                /* B */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

                /* C */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                /* D */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                /* E */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                /* F */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        };

std::string UrlHelper::url_encode(const std::string &value) {
    const char DEC2HEX[16 + 1] = "0123456789ABCDEF";
    const unsigned char *pSrc = (const unsigned char *) value.c_str();
    const long SRC_LEN = value.length();
    unsigned char *const pStart = new unsigned char[SRC_LEN * 3];
    unsigned char *pEnd = pStart;
    const unsigned char *const SRC_END = pSrc + SRC_LEN;

    for (; pSrc < SRC_END; ++pSrc) {
        if (SAFE[*pSrc])
            *pEnd++ = *pSrc;
        else {
            // escape this char
            *pEnd++ = '%';
            *pEnd++ = DEC2HEX[*pSrc >> 4];
            *pEnd++ = DEC2HEX[*pSrc & 0x0F];
        }
    }

    std::string sResult((char *) pStart, (char *) pEnd);
    delete[] pStart;
    return sResult;
}

std::string UrlHelper::url_decode(const std::string &value) {
    // Note from RFC1630: "Sequences which start with a percent
    // sign but are not followed by two hexadecimal characters
    // (0-9, A-F) are reserved for future extension"

    const unsigned char *pSrc = (const unsigned char *) value.c_str();
    const int SRC_LEN = value.length();
    const unsigned char *const SRC_END = pSrc + SRC_LEN;
    // last decodable '%'
    const unsigned char *const SRC_LAST_DEC = SRC_END - 2;

    char *const pStart = new char[SRC_LEN];
    char *pEnd = pStart;

    while (pSrc < SRC_LAST_DEC) {
        if (*pSrc == '%') {
            char dec1, dec2;
            if (-1 != (dec1 = HEX2DEC[*(pSrc + 1)])
                && -1 != (dec2 = HEX2DEC[*(pSrc + 2)])) {
                *pEnd++ = (dec1 << 4) + dec2;
                pSrc += 3;
                continue;
            }
        }

        *pEnd++ = *pSrc++;
    }

    // the last 2- chars
    while (pSrc < SRC_END)
        *pEnd++ = *pSrc++;

    std::string sResult(pStart, pEnd);
    delete[] pStart;
    return sResult;
}

std::vector<std::string> UrlHelper::array_elements(std::string const & s) {
    std::vector<std::string> ret;
    const char *error;
    int   erroffset;
    int   rc;
    int   ovector[100];
    unsigned int offset = 0;
    unsigned long len = s.length();

    size_t bracket_start_pos = s.find_first_of("[");

    if (bracket_start_pos == std::string::npos) {

        ret.push_back(s);
        return ret;
    } else {
        size_t bracket_end_pos = s.find_first_of("]",bracket_start_pos+1);
        //check if string has valid brackets
        if (bracket_end_pos != std::string::npos) {
            ret.push_back(s.substr(0,bracket_start_pos));
        } else {
            ret.push_back(s);
            return ret;
        }
    }

    //get all data from brackets
    if (!re)
    {
        re = pcre_compile (array_pattern.c_str(),          /* the pattern */
                           PCRE_MULTILINE,
                           &error,         /* for error message */
                           &erroffset,     /* for error offset */
                           0);             /* use default character tables */
        if (!re) {
            printf("pcre_compile failed (offset: %d), %s\n", erroffset, error);
            return ret;
        }
    }

    while (offset < len && (rc = pcre_exec(re, 0, s.c_str(), len, offset, 0, ovector, sizeof(ovector))) >= 0)
    {
        for(int i = 0; i < rc; ++i)
        {
            ret.push_back(s.substr(ovector[2*i]+1,ovector[2*i+1] - ovector[2*i]-2));
        }
        offset = ovector[1];
    }
    return ret;
}