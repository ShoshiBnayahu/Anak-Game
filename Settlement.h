#pragma once
#include "GroundObject.h"

class Settlement : public GroundObject {
private:
    static int cityCounter;
    static int villageCounter;
    std::unordered_map<std::string, int> resources;

public:
    Settlement(int x, int y, GroundObjectType type, bool isComplete);
    static int getCityCounter();
    static int getVillageCounter();
    void makeEmpty() override;
    void addResource(const std::string& resource, int amount);
    std::vector<int> selectedResource();
    int getPeopleCount();
    int getCarCount();
    int getTruckCount();
};

