#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ReadJson.h"
#include "Tile.h"
#include "Coordinate.h"
#include "Settlement.h"

class World
{
private:
    std::vector<std::vector<Tile *>>tileGrid;
    std::vector<std::vector<Coordinate*>>cellGrid;
    std::map<string, int> rainsLeft;
    std::vector< GroundObject*> groundObjects;
    


public:
    void fillTileGrid(const std::vector< std::vector<std::string> >& data);
    void fillCellGrid();
    void buildGroundObject(std::string type, int x, int y , bool iscomplate);
    Settlement* isSettlement(std::pair<int, int> cell);
    bool canBuild(int x, int y, int sizeX, int sizeY);
    std::vector<std::vector<Tile*>> & getGrid() { return tileGrid; }
    Tile * & selectTile(int x, int y);
    bool insertResource(int amount, string resrouce, int x, int y);
    std::vector<int> selectedResource(std::pair<int, int>cell);
    string selectedCategory(std::pair<int,int>cell);
    int selectedPeople(std::pair<int, int>cell);
    bool insertPeople(int amount, int x, int y);
    void peopleWork(std::pair<int, int> prev, std::pair<int, int> next);
    void rainFall(int amount);
    std::string selectedComplete(std::pair<int, int> cell);
    int cityCount();

    int villageCount();

    int roadCount();

    void makeEmpty(int x, int y);



    
};