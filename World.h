#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ReadJson.h"
#include "Tile.h"

class World
{
private:
    std::vector<std::vector<Tile *>>grid;
    std::map<string, int> rainsLeft;

public:
    void fillGrid(const std::vector< std::vector<std::string> >& data);
    std::vector<std::vector<Tile*>> & getGrid() { return grid; }
    Tile * & selectTile(int x, int y);
    bool insertResource(int amount, string resrouce, int x, int y);
    std::vector<int> selectedResource(std::pair<int, int>cell);
    string& selectedCategory(std::pair<int,int>cell);
    bool insertPeople(int amount, int x, int y);
    void peopleWork(std::pair<int, int> prev, std::pair<int, int> next);
    void rainFall(int amount);
    
};