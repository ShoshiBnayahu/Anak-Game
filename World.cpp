#include "World.h"



void World::fillGrid(const std::vector<std::vector<std::string>>& data)
{

    for (size_t i = 0; i < data.size(); i++)
    {
        grid.push_back(std::vector<Tile*>());
        for (size_t j = 0; j < data[i].size(); j++)
        {
            if (stoi(data[i][j]) < 3)
                grid[i].push_back(new Tile(std::stoi(data[i][j])));
            else
                grid[i].push_back(new TileResource(std::stoi(data[i][j])));

        }
    }
}

Tile*& World::selectTile(int x, int y)
{
    return grid[(y - 1) / ReadJson::sizeOfTiles[0]][(x - 1) / ReadJson::sizeOfTiles[1]];
}



//bool World::insertResource(int amount, string resource, int x, int y)
//{
//    Tile* t = selectTile(x, y);
//    if (t->getTile().second < 3) {
//        return false;
//    }
//    if (((TileResource*)t)->getResourceType() != resource) {
//        return false;
//    }
//    ((TileResource*)t)->addResource(x - 1, y - 1, amount);
//    return true;
//}

//std::vector<int> World::selectedResource()
//{
//    std::vector<int> amount;
//    for (auto a : ReadJson::resourceTypes)
//    {
//        if (Resource::resourceCounter.find(a) != Resource::resourceCounter.end())
//            amount.push_back(Resource::resourceCounter[a]);
//        else
//            amount.push_back(0);
//    }
//    amount.pop_back();
//    return amount;
//}
bool World::insertResource(int amount, string resource, int x, int y)
{
    Tile* t = selectTile(x, y);
    if (t->getTile().second < 3) {
        return false;
    }
    if (((TileResource*)t)->getResourceType() != resource) {
        return false;
    }
    ((TileResource*)t)->addResource(amount);
    return true;
}



std::vector<int> World::selectedResource(std::pair<int, int>cell)
{
    return selectTile(cell.first, cell.second)->selectedResource();
}
string& World::selectedCategory(std::pair<int, int>cell)
{
    return selectTile(cell.first, cell.second)->getTile().first;
}

bool World::insertPeople(int amount, int x, int y)
{
    Tile* tile = selectTile(x, y);
    tile->addPeople(x - 1, y - 1);
    return true;
}

void World::peopleWork(std::pair<int, int> prev, std::pair<int, int> next)
{
    selectTile(prev.first, prev.second)->subPeople(prev.first - 1, prev.second - 1);
    Tile* newTile = selectTile(next.first, next.second);
    newTile->addPeople(next.first - 1, next.second - 1);
    ((TileResource*)newTile)->subResource(1);
}

void World::rainFall(int amount)
{
    std::string resourceName;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++) 
        {
            TileResource* tileResourcePtr = dynamic_cast<TileResource*>(grid[i][j]);
            if (tileResourcePtr != nullptr) {
                resourceName = tileResourcePtr->getResourceType();
                if (ReadJson::rains.find(resourceName) != ReadJson::rains.end())
                    tileResourcePtr->addResource((amount + rainsLeft[resourceName]) /
                        ReadJson::rains[resourceName]);
            }
        }
            
            
              /*  cout << resourceName << "\n";
                if (ReadJson::rains.find(resourceName) != ReadJson::rains.end())   
                    ((TileResource*)(grid[i][j]))->addResource((amount + rainsLeft.at(resourceName)) /
                    ReadJson::rains.at(resourceName));
                  
            }*/
               
            /*if(typeid(grid[i][j])==typeid(TileResource*)&&
           ReadJson::rains.find(((TileResource*)(grid[i][j]))->getResourceType()) != ReadJson::rains.end())
                ((TileResource*)(grid[i][j]))->addResource(amount + rainsLeft.at(()
                   / ReadJson::rains[((TileResource*)(grid[i][j]))->getResourceType())];*/
 
    for (auto rl : rainsLeft) 
        rl.second =( amount + rl.second) % ReadJson::rains[rl.first];
    
}
