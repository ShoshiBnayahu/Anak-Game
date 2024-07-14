#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ReadJson.h"
#include "Tile.h"
#include "Coordinate.h"
#include "Settlement.h"
#include "Road.h"


class World
{
private:
    std::vector<std::vector<Tile*>> tileGrid;
    std::vector<std::vector<Coordinate*>> cellGrid;
    std::map<std::string, int> rainsLeft;
   
public:
    // Functions
    void fillTileGrid(const std::vector<std::vector<std::string>>& data);
    void fillCellGrid();
    int buildGroundObject(std::string type, int x, int y, bool isComplete);
    Settlement* isSettlement(std::pair<int, int> cell);
    Road* isRoad(std::pair<int, int> cell);
    Coordinate* getCell(std::pair<int, int>cell);
    Coordinate* getCell(int x,int y);
    bool canBuild(int x, int y, int sizeX, int sizeY);
    std::vector<std::vector<Tile*>>& getGrid() { return tileGrid; }
    Tile*& selectTile(int x, int y);
    bool putInCellGrid(Location* location, ObjectType type, std::vector<int> size);
    bool putInCellGrid(ObjectType type, std::vector<int> size, std::pair<int, int>cell);
    void insertResource(int amount, std::string resource, int x, int y);
    std::vector<int> selectedResource(std::pair<int, int> cell);
    std::string selectedCategory(std::pair<int, int> cell);
    int selectedPeople(std::pair<int, int> cell);
    bool insertPeople(int amount, int x, int y);
    void peopleWork(std::pair<int, int> prev, std::pair<int, int> next);
    void deposit(std::pair<int, int> prev, std::pair<int, int> next);
    void takeResources(std::pair<int, int> prev, std::pair<int, int> next);
    std::pair<int, int> move(std::pair<int, int> prev, std::pair<int, int> next);
    void rainFall(int amount);
    void insertResources(std::vector<int>, int x, int y);
    std::string selectedComplete(std::pair<int, int> cell);
    bool isExistResource(std::vector<int> cost, std::unordered_map<string, int>exist);
    bool manufacture(std::string type, int x, int y,bool checkResource);
    int selectedCar(std::pair<int, int> cell);
    int selectedTruck(std::pair<int, int> cell);
    void makeEmpty(int x, int y);
    int cityCount();
    int villageCount();
    int roadCount();
    int carCount();
    int truckCount();
    int hlicopterCount();
};