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

public:
    World(const std::vector< std::vector<std::string> >& data){ fillGrid(data); };
    void fillGrid(const std::vector< std::vector<std::string> >& data);
    std::vector<std::vector<Tile*>> & getGrid() { return grid; }

    Tile * & selectTile(int x, int y);

    bool insertResource(int amount, string resrouce, int x, int y);
    
    std::vector<int> selectedResource();







    
};