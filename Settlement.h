#pragma once
#include "GroundObject.h"

class Settlement : public GroundObject , public Resource{
private:
    static int cityCounter;
    static int villageCounter;
    int peoples=0;
    int cars=0;
    int trucks=0;
    int helicopters=0;
    //std::unordered_map<std::string, int> resources;

public:
    Settlement(int x, int y, GroundObjectType type, bool isComplete);
    static int getCityCounter();
    static int getVillageCounter();
    void makeEmpty() override;
    void addResource( std::string resource, int amount) override;
    std::vector<int> selectedResource();
    void addPeople(int amount);
    void subPeople(int amount);
    int getPeoples() const { return peoples; }
    void addCar(int amount);
    int getCars() const { return cars; }
    void addTruck(int amount);
    int getTrucks() const { return trucks; }
    void addHelicopter(int amount);
    int getHelicopters() const { return helicopters; }

 /*   int getPeopleCount();
    int getCarCount();
    int getTruckCount();*/
};

