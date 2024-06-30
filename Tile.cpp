#include "Tile.h"

Tile::Tile(int tailNum)
{
	std::string name = ReadJson::Tiles[tailNum];
	tile.first = name;
	tile.second = tailNum;
}
TileResource::TileResource(int tailNum) : Tile(tailNum) {
	resourceType = ReadJson::resourceTypes[tailNum - 3];
}

void TileResource::addResource(int x, int y,int amount) {
	if (resources.find(pair<int, int>(x, y)) == resources.end())
		resources[pair<int, int>(x, y)] = Resource(resourceType, amount);
	else
		resources[pair<int, int>(x, y)] += amount;
}