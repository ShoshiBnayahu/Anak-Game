#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ReadJson.h"
#include "Tile.h"
#include "Coordinate.h"
#include "Settlement.h"

class World
{
private:
    std::vector<std::vector<Tile*>> tileGrid;
    std::vector<std::vector<Coordinate*>> cellGrid;
    std::map<std::string, int> rainsLeft;
    std::vector<GroundObject*> groundObjects;



    //std::vector<GroundTransportation*> groundTransportations;


public:
    // Functions
    void fillTileGrid(const std::vector<std::vector<std::string>>& data);
    void fillCellGrid();
    void buildGroundObject(std::string type, int x, int y, bool isComplete);
    Settlement* isSettlement(std::pair<int, int> cell);
    bool canBuild(int x, int y, int sizeX, int sizeY);
    std::vector<std::vector<Tile*>>& getGrid() { return tileGrid; }
    Tile*& selectTile(int x, int y);
    bool insertResource(int amount, std::string resource, int x, int y);
    std::vector<int> selectedResource(std::pair<int, int> cell);
    std::string selectedCategory(std::pair<int, int> cell);
    int selectedPeople(std::pair<int, int> cell);
    bool insertPeople(int amount, int x, int y);
    void peopleWork(std::pair<int, int> prev, std::pair<int, int> next);
    //bool isGroundTransportation(std::pair<int, int> cell);
    void rainFall(int amount);
    std::string selectedComplete(std::pair<int, int> cell);
    bool manufactureGroundTransportation(std::string type, int x, int y);
    int selectedCar(std::pair<int, int> cell);
    int selectedTruck(std::pair<int, int> cell);
    int cityCount();
    int villageCount();
    int roadCount();
    void makeEmpty(int x, int y);
};