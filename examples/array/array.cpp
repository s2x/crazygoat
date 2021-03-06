//
// Created by piotr on 02.11.16.
//
#include "../../include/crazygoat/Array.h"

void node_get_leafs(Array *root, std::vector<Array *> *leafs) {

    if (root->hasChildrens()) {
        auto tmp = root->getChildrens();
        for (auto it: tmp) {
            node_get_leafs(it, leafs);
        }

    } else {

        leafs->push_back(root);
    }
}

std::string build_http_query(Array *root) {
    std::vector<Array *> leafs;

    node_get_leafs(root, &leafs);
    std::string query = "";
    auto last = &leafs.back();
    for (auto & it:leafs) {
        std::string name = "";
        Array *parent = it;
        while (parent->getParent()->getParent()) {
            name = "[" + parent->getName() + "]" + name;
            parent = parent->getParent();
        }
        query += parent->getName() + name + "=" + it->getValue();
        if (&it != last) {
            query += "&";
        }
    }
    return query;
}

int main(void) {

    Array test;
    test["id"] = "1";
    test["title"] = "test titile";
    test["book"]["1"]["name"] = "1";
    test["book"]["1"]["author"] = "John Smith";

    //autoinc
    test["autoinc"][""] = "0";
    test["autoinc"][""] = "1";
    test["autoinc"][""] = "2";
    test["autoinc"][""] = "3";
    test["autoinc"]["8"] = "8";
    test["autoinc"]["abc"] = "abc";
    test["autoinc"][""] = "9";

    std::cout<<"Query:"<<build_http_query(&test)<<std::endl;

    Array test1;
    test1["1"]["Name"] = "2";
    test1["2"]["Name"] = "2";
    Array test2 = test1;


    if (test1["1"] == test1["2"]) {
        std::cout << "Test operator == true" << std::endl;
    } else {
        std::cout << "Test operator == false" << std::endl;
    }

    //testing if exists
    if (test["check"]["if"]["exists"]) {
        std::cout << "Check fail\n";
    } else {
        std::cout << "Check ok\n";
    }
    std::vector<Array *> leafs;
    node_get_leafs(&test1, &leafs);
    std::cout<<"leafs: "<<leafs.size()<<std::endl;

    for (auto it: leafs) {
        Array *parent = it;
        std::string name = "";
        while (parent->getParent()) {
            name = parent->getName() + name;
            parent = parent->getParent();
            if (parent->getParent())
                name = "." + name;
        }
        std::cout << name << "=" << it->getValue() << std::endl;
    }

    std::cout<<"Using copy!"<<std::endl;
    leafs.clear();
    node_get_leafs(&test2, &leafs);
    std::cout<<"leafs: "<<leafs.size()<<std::endl;
    for (auto it: leafs) {
        Array *parent = it;
        std::string name = "";
        while (parent->getParent()) {
            name = parent->getName() + name;
            parent = parent->getParent();
            if (parent->getParent())
                name = "." + name;
        }
        std::cout << name << "=" << it->getValue() << std::endl;
    }

}