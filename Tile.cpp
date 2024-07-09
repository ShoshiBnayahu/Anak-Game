#include "Tile.h"
#include "Car.h"
Tile::Tile(int tileNum)
{
	std::string name = ReadJson::tiles[tileNum];
	tile.first = name;
	tile.second = tileNum;
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

void Tile::addCar(int x, int y)
{
	//cars[pair<int, int>(x, y)] = GroundTransportation(GroundTransportationType::Car);
	cars[pair<int, int>(x, y)] = Car();
}

void Tile::subCar(int x, int y)
{
	auto c = trucks.find(std::pair<int, int>(x, y));
	if (c != trucks.end())
		trucks.erase(c);
}

void Tile::addTruk(int x, int y)
{
	//trucks[pair<int, int>(x, y)] = GroundTransportation(GroundTransportationType::Car);
	trucks[pair<int, int>(x, y)] = Truck();

}

void Tile::subTruck(int x, int y)
{
	auto t = trucks.find(std::pair<int, int>(x, y));
	if (t != trucks.end())
		trucks.erase(t);
}
//void TileResource::addResource(int x, int y, int amount)
//{
//	if (resources.find(resourceType) == resources.end())
//		resources[pair<int, int>(x, y)] = Resource(resourceType, amount);
//	else
//		resources[pair<int, int>(x, y)] += amount;
//}
TileResource::TileResource(int tileNum):Tile(tileNum)
{
	resourceType = ReadJson::tilesResourceType[tile.first];
}
void TileResource::addResource(int amount)
{
	resources[resourceType] += amount;
}

void TileResource::subResource(int amount)
{
	resources[resourceType] -= amount;
}


