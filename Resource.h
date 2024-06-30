#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class Resource {

private:
    int amount;
    std::string name;


public:
    Resource() { };
    Resource(std::string _name, int _amount = 0);
    const int& getAmount() const {
        return amount;
    }
    Resource& operator+=(int addAmount);
     static std::unordered_map<std::string, int> resourceCounter;

};

