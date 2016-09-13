//
// Created by piotr on 13.09.16.
//

#include "../src/Filters/Filter.h"

std::string helloString = "Hello world";

class myFilter: public Filter {
public:
    Response invoke(Request request, Response response) {
        response.setContent(helloString);
        return response;
    }
};

int main()
{
    Response response;
    Request request;
    myFilter filter;

    response = filter.invoke(request, response);

    if (helloString != response.getContent()) {
        std::cerr<<"Content not equal!!! "<<"Expected ["<<helloString<<"], got ["<<response.getContent()<<"]\n";
        return 1;
    }

    if (response.getHeader("Content-type") != "text/html") {
        std::cerr<<"Wrong Content-type!!! "
        <<"Expected [text/html], got ["<<response.getHeader("Content-type")<<"]\n";
        return 2;
    }

    if (response.getHeader("Content-length") != std::to_string(helloString.length())) {
        std::cerr<<"Wrong Content-length!!! "
        <<"Expected [text/html], got ["<<response.getHeader("Content-length")<<"]\n";
        return 3;
    }

    return 0;
}