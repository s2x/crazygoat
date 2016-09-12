//
// Created by piotr on 12.09.16.
//

#include <iostream>
#include <fcgio.h>
#include "App.h"
#include "Request.h"

App::App() {
    // set read buffers
    this->cin_streambuf = std::cin.rdbuf();
    this->cout_streambuf = std::cout.rdbuf();
    this->cerr_streambuf = std::cerr.rdbuf();
}

App::~App() {
#if HAVE_IOSTREAM_WITHASSIGN_STREAMBUF
    cin = this->cin_streambuf;
    cout = this->cout_streambuf;
    cerr = this->cerr_streambuf;
#else
    std::cin.rdbuf(this->cin_streambuf);
    std::cout.rdbuf(this->cout_streambuf);
    std::cerr.rdbuf(this->cerr_streambuf);
#endif
}

Response App::processRequest(FCGX_Request fcgi_request) {
    //proces fastcgi headers
    Request request(fcgi_request);
    Response response;
    if (filters.size()) {
        response = this->filters.front().processNext(request, response);
    }
    //return response
    return response;
}


/**
 * main applicaton loop
 */
void App::run() {

    FCGX_Request request;

    // configure some fastcgi data
    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    //wait for valid request
    while (FCGX_Accept_r(&request) == 0) {

        // set streams
        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

#if HAVE_IOSTREAM_WITHASSIGN_STREAMBUF
        cin = &cin_fcgi_streambuf;
        cout = &cout_fcgi_streambuf;
        cerr = &cerr_fcgi_streambuf;
#else
        std::cin.rdbuf(&cin_fcgi_streambuf);
        std::cout.rdbuf(&cout_fcgi_streambuf);
        std::cerr.rdbuf(&cerr_fcgi_streambuf);
#endif
        //process request;
        Response resp = this->processRequest(request);

        //return headers and content
        FCGX_FPrintF(request.out, "%s"
                "\r\n"
                "%s", resp.getHeaders().c_str(), resp.getContent().c_str());

        //fastcig cleanup
        FCGX_Finish_r(&request);
    }

;
}

void App::addFilter(Filter filter) {
    this->filters.push_back(filter);
}

