//
// Created by piotr on 12.09.16.
//

#include "../../include/crazygoat/App.h"

class myFilter : public Filter {
    Response invoke(Request request, Response response) {
        response.setContent("Hello world");
        return response;
    }
};

class myApp : public App {
    void configure() {
        this->addFilter(new myFilter());
    }
};

int main()
{
    myApp app;
    app.run();
}