#include "World.h"



void World::fillGrid(const std::vector<std::vector<std::string>>& data)
{
    
    for (size_t i = 0; i < data.size(); i++)
    {
        grid.push_back(std::vector<Tile*>());
        for (size_t j = 0; j < data[i].size(); j++)
        {
            if(stoi(data[i][j])<3)
                 grid[i].push_back(new Tile(std::stoi(data[i][j])));
            else                 
                grid[i].push_back(new TileResource(std::stoi(data[i][j])));

        }
    }
}

Tile * & World::selectTile(int x, int y)
{
    return grid[(y - 1) / ReadJson::SizeOfTiles[0]][(x - 1) / ReadJson::SizeOfTiles[1]];
}



bool World::insertResource(int amount, string resource, int x, int y)
{
    Tile* t = selectTile(x, y);
    if (t->getTile().second < 3) {
        delete t;
        return false;
    }
    if (((TileResource*)t)->getResourceType() != resource) {
        delete t;
        return false;
    }
    ((TileResource*)t)->addResource(x - 1, y - 1, amount);
    delete t;
    return true;
}

std::vector<int> World::selectedResource()
{
    std::vector<int> amount;
    for (auto a : ReadJson::resourceTypes)
    {
        if (Resource::resourceCounter.find(a) != Resource::resourceCounter.end())
            amount.push_back(Resource::resourceCounter[a]);
        else
            amount.push_back(0);
    }
    amount.pop_back();
    return amount;
}