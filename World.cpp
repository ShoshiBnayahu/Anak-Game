#include "World.h"
#include "Road.h"
#include "Settlement.h"

void World::fillTileGrid(const std::vector<std::vector<std::string>>& data)
{

    for (size_t i = 0; i < data.size(); i++)
    {
        tileGrid.push_back(std::vector<Tile*>());
        for (size_t j = 0; j < data[i].size(); j++)
        {
            //אם אין לו סוג משאב מיחד לו
            if (ReadJson::tilesResourceType.find(ReadJson::tiles[std::stoi(data[i][j])])== ReadJson::tilesResourceType.end())
                tileGrid[i].push_back(new Tile(std::stoi(data[i][j])));
            else
                tileGrid[i].push_back(new TileResource(std::stoi(data[i][j])));

        }
    }
}

void World::fillCellGrid()
{
    for (int i = 0; i < tileGrid.size()* ReadJson::sizes["Tile"][1]; i++)
    {
        cellGrid.push_back(std::vector<Coordinate*>());
        for (int j = 0; j < tileGrid[0].size() * ReadJson::sizes["Tile"][0]; j++)
        {

            cellGrid[i].push_back(new Coordinate(tileGrid[i/ ReadJson::sizes["Tile"][1]][j/ ReadJson::sizes["Tile"][0]]));
        }
    }
}

void World::buildGroundObject(std::string type, int x, int y , bool isComplate)
{
    /*if (cell[Gridy - 1][x - 1]->getGroundObject() != nullptr)
    return;*/
    bool flag = false;
    if (type == GroundObject::typeToString(GroundObjectType::Road)) 
    {
        groundObjects.push_back(new Road(x - 1, y - 1, GroundObjectType::Road, isComplate));
        flag = true;
    }
       
    else if (type == GroundObject::typeToString(GroundObjectType::City)) {
        if (isComplate || canBuild(x - 1, y - 1, ReadJson::sizes[type][0], ReadJson::sizes[type][1]))
        {
            groundObjects.push_back(new Settlement(x - 1, y - 1, GroundObjectType::City, isComplate));
            flag = true;

        }
    }
    else if (type == GroundObject::typeToString(GroundObjectType::Village)) {
        if (isComplate || canBuild(x - 1, y - 1, ReadJson::sizes[type][0], ReadJson::sizes[type][1]))
        {
            groundObjects.push_back(new Settlement(x - 1, y - 1, GroundObjectType::Village, isComplate));
            flag = true;

        }
    }
        for (int i = y - 1; i <  y - 1+ ReadJson::sizes["City"][1] && flag; i++)
            for (int j = x - 1; j < x - 1+ ReadJson::sizes["City"][0]; j++)
                cellGrid[i][j]->setGroundObject(groundObjects.back());
}

Settlement* World::isSettlement(std::pair<int, int> cell)
{
    if (cellGrid[cell.second - 1][cell.first - 1]->getGroundObject()) {
        Settlement* s = dynamic_cast<Settlement*>(cellGrid[cell.second - 1][cell.first - 1]->getGroundObject());
        if (s) {
            return s;
        }
    }
    return nullptr;
}

bool World::canBuild(int x, int y, int sizeX, int sizeY) {
    int road = ReadJson::sizes["Road"][0];
    for (size_t i = x + road - 1; y - 1 >= 0 && i < x + sizeX - road + 1; i++)
        if (cellGrid[y - 1][i]->getGroundObject() && cellGrid[y - 1][i]->getGroundObject()->getType() == GroundObjectType::Road)
            return true;
    for (size_t i = x + road - 1; y + sizeY >= 0 && i < x + sizeX - road + 1; i++)
        if (cellGrid[y + sizeY][i]->getGroundObject() && cellGrid[y + sizeY][i]->getGroundObject()->getType() == GroundObjectType::Road)
            return true;
    for (size_t i = y + road - 1; x - 1 >= 0 && i < y + sizeY - road + 1; i++)
        if (cellGrid[i][x - 1]->getGroundObject() && cellGrid[i][x - 1]->getGroundObject()->getType() == GroundObjectType::Road)
            return true;
    for (size_t i = y + road - 1; x + sizeX >= 0 && i < y + sizeY - road + 1; i++)
        if (cellGrid[i][x - 1]->getGroundObject() && cellGrid[i][x + sizeX]->getGroundObject()->getType() == GroundObjectType::Road)
            return true;
    return false;
}

Tile*& World::selectTile(int x, int y)
{
    return tileGrid[(y - 1) / ReadJson::sizes["Tile"][0]][(x - 1) / ReadJson::sizes["Tile"][1]];
}

std::string World::selectedComplete(std::pair<int, int> cell)
{
    return cellGrid[cell.second - 1][cell.first - 1]->getGroundObject()->isComplete() ? "true" : "false";
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
    Settlement* s = isSettlement(std::pair<int, int>(x, y));
        if (s) {
            s->addResource(resource, amount);
            return true;
        }
    Tile* t = selectTile(x, y);
    TileResource* tr = dynamic_cast<TileResource*>(t);
    if (!tr|| tr->getResourceType() != resource) {
        return false;
    }
    tr->addResource(amount);
    return true;
}

std::vector<int> World::selectedResource(std::pair<int, int>cell)
{
    return selectTile(cell.first, cell.second)->selectedResource();
}

 std::string  World::selectedCategory(std::pair<int, int> cell)
{
    if (cellGrid[cell.second - 1][cell.first - 1]->getGroundObject() )
        return GroundObject::typeToString(cellGrid[cell.second - 1][cell.first - 1]->getGroundObject()->getType());
    return  cellGrid[cell.second - 1][cell.first - 1]->getTile()->getTile().first;
}

 bool World::insertPeople(int amount, int x, int y)
 {
     Settlement* s = isSettlement(std::pair<int,int>(x,y));
         if (s) {
             s->addResource("People", amount);
             return true;
         }
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

int World::selectedPeople(std::pair<int, int>cell)
{
  Settlement* s = isSettlement(cell);
        if (s)
            return s->getPeopleCount();
    return cellGrid[cell.second - 1][cell.first - 1]->getTile()->getPeople().size();
}

void World::rainFall(int amount)
{
    std::string resourceName;
    for (int i = 0; i < tileGrid.size(); i++)
        for (int j = 0; j < tileGrid[0].size(); j++)
        {
            TileResource* tileResourcePtr = dynamic_cast<TileResource*>(tileGrid[i][j]);
            if (tileResourcePtr) {
                resourceName = tileResourcePtr->getResourceType();
                if (ReadJson::rains.find(resourceName) != ReadJson::rains.end()) 
                    tileResourcePtr->addResource((amount + rainsLeft[resourceName]) /
                        ReadJson::rains[resourceName]);
                    
            }
        }
    for (auto rl : rainsLeft) 
        rl.second =( amount + rl.second) % ReadJson::rains[rl.first];
    
}

void World::insertManufactur(std::string type, int x, int y) {

}

int World::cityCount()
{
    return Settlement::getCityCounter();
}

int World::villageCount()
{
    return Settlement::getVillageCounter();
}

int World::roadCount()
{
    return Road::getRoadCounter();
}

void World::makeEmpty(int x, int y) {
    if (cellGrid[y - 1][x - 1]->getGroundObject())
        cellGrid[y - 1][x - 1]->getGroundObject()->makeEmpty();
}



