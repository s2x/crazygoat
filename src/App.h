//
// Created by piotr on 12.09.16.
//

#ifndef CRAZYGOAT_APP_H
#define CRAZYGOAT_APP_H

#include <streambuf>
#include <fcgiapp.h>

#include "Response.h"
#include "Filter.h"

class App {
protected:

    Response processRequest(FCGX_Request fcgi_request);
    std::vector<Filter *> filters;

    std::streambuf *cin_streambuf;
    std::streambuf *cout_streambuf;
    std::streambuf *cerr_streambuf;
public:
    App();
    virtual ~App();
    virtual void configure() { };
    void run();

    void addFilter(Filter *filter);
};


#endif //CRAZYGOAT_APP_H
