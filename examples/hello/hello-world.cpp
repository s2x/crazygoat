//
// Created by piotr on 12.09.16.
//

#include "../../src/App.h"

class myFilter : public Filter {
    Response invoke(Request request, Response response) {
        response.setContent("Hello world");
        return response;
    }
};

class myApp : public App {
    void configure() {
        myFilter helloWorld;
        this->addFilter(helloWorld);
    }
};

int main()
{
    App app;
    app.run();
}