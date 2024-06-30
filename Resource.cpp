
#include "Resource.h"

std::unordered_map<std::string, int> Resource::resourceCounter;

Resource::Resource(std::string _name, int _amount) :name(_name), amount(_amount) {
    if (resourceCounter.find(name) != resourceCounter.end())
        resourceCounter[name] = 0;
    else
        resourceCounter[name] += _amount;
}
Resource& Resource::operator+=(int addAmount) {
    amount += addAmount;
    resourceCounter[name] += addAmount;
    return *this;
}
 

