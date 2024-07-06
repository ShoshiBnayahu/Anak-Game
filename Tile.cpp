#include "Tile.h"

Tile::Tile(int tailNum)
{
	std::string name = ReadJson::tiles[tailNum];
	tile.first = name;
	tile.second = tailNum;
}
std::vector<int> Tile::selectedResource()
{
	std::vector<int> amount;
	for (const auto& res : ReadJson::resourceTypes) {
		if (resources.find(res.first) != resources.end())
			amount.push_back(resources.at(res.first));
		else
			amount.push_back(0);
	}
	//pop the people resource 
	amount.pop_back();
	return amount;
}
void Tile::addPeople(int x, int y)
{
	peoples[pair<int, int>(x, y)] = People();
}
void Tile::subPeople(int x, int y)
{
	auto p = peoples.find(std::pair<int, int>(x, y));
	if (p != peoples.end())
		peoples.erase(p);
}


TileResource::TileResource(int tailNum) : Tile(tailNum) {
	resourceType = ReadJson::tilesResourceType[tile.first];
	///An initial value determination must be added according to the JSON
	///resources[resourceType]=readJson start amount of this resource
	resources [resourceType] = 0;
}



//void TileResource::addResource(int x, int y, int amount)
//{
//	if (resources.find(resourceType) == resources.end())
//		resources[pair<int, int>(x, y)] = Resource(resourceType, amount);
//	else
//		resources[pair<int, int>(x, y)] += amount;
//}
void TileResource::addResource(int amount)
{
	resources[resourceType] += amount;
}
void TileResource::subResource(int amount)
{
	resources[resourceType] -= amount;
}


