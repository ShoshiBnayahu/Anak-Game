#include "Settlement.h"
int Settlement::cityCounter=0;
int Settlement::villageCounter=0;

Settlement::Settlement(int x, int y, GroundObjectType type, bool isComplete) : GroundObject(x, y, type, isComplete) {
    if (type == GroundObjectType::Road) {
        throw std::invalid_argument("Invalid type: Cannot create Settlement with type Road");
    }
    if (type == GroundObjectType::City) {
        cityCounter++;
    }
    if (type == GroundObjectType::Village) {
        villageCounter++;
    }
}

int Settlement::getCityCounter()
{
    return cityCounter;
}

int Settlement::getVillageCounter()
{
    return villageCounter;
}

void Settlement::makeEmpty() {
    for (auto& res : resources)
        res.second = 0;
}

std::vector<int> Settlement::selectedResource()
{
    std::vector<int> amount;
    for (const auto& res : ReadJson::resourceTypes) {
        if (resources.find(res.first) != resources.end())
            amount.push_back(resources.at(res.first));
        else
            amount.push_back(0);
    }
    //pop the people resource 
    amount.pop_back();
    return amount;
}

void Settlement::addResource(const std::string& resource, int amount) {
    if (resources.find(resource) != resources.end()) {
        resources[resource] = std::min(resources[resource] + amount, ReadJson::capacities[typeToString(type)][ReadJson::resourceTypes[resource]]);
    }
    else {
        resources[resource] = std::min(amount, ReadJson::capacities[typeToString(type)][ReadJson::resourceTypes[resource]]);
    }
}

int Settlement::getPeopleCount() {
    auto it = resources.find("People");
    if (it != resources.end()) {
        return it->second;
    }
    return 0;
}

int Settlement::getCarCount() {
    auto it = resources.find("Car");
    if (it != resources.end()) {
        return it->second;
    }
    return 0;
}
int Settlement::getTruckCount() {
    auto it = resources.find("Truck");
    if (it != resources.end()) {
        return it->second;
    }
    return 0;
}