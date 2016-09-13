//
// Created by piotr on 13.09.16.
//

//
// Created by piotr on 12.09.16.
//

#include "../../src/App.h"

/**
 *  Simple action
 */
class myFilter : public Filter {
    Response invoke(Request request, Response response) {
        //print some nasty words about goat
        response.setContent("You stupid goat!");
        return response;
    }
};

/**
 * Simple filter class, remove word stupid from content
 */
class myCensorshipFilter : public Filter {
    Response invoke(Request request, Response response) {
        //first we must run main action
        response = this->next->invoke(request, response);

        //removing some vulgar words
        std::string content = response.getContent();
        std::string toReplace = "stupid";
        std::string replaceWith = "--censored--";
        std::string censored = (content.replace(content.find(toReplace), toReplace.length(), replaceWith));

        //set censored content
        response.setContent(censored);

        return response;
    }
};

/**
 *
 */
class myApp : public App {
private:

    //our filters
    myCensorshipFilter censorshipFilter;
    myFilter actionFilter;

    void configure() {
        //first add censor filter - most important
        //next add action filter
        this->addFilter(&censorshipFilter)->addFilter(&actionFilter);
    }
};

int main()
{
    myApp app;
    app.run();
}