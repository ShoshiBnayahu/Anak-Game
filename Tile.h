#pragma once
#include <iostream>
#include "ReadJson.h"
#include "Resource.h"


namespace std {
	template <>
	struct hash<pair<int, int>> {
		size_t operator()(const pair<int, int>& p) const {
			auto hash1 = hash<int>{}(p.first);
			auto hash2 = hash<int>{}(p.second);
			return hash1 ^ (hash2 << 1);
		}
   };
}

class Tile:public Resource
{
protected:

	std::pair<std::string, int> tile;
	/*const int weight = ReadJson::sizes["Tile"][1];
	const int height = ReadJson::sizes["Tile"][0];*/
	int peoples = 0;
	int cars = 0;
	int trucks = 0;
	int helicopters = 0;
	std::unordered_map<string, int> resources;

public:
	Tile(int tileNum);
	std::pair<string, int>& getTile() { return tile; };
	void addPeople(int amount);
	void subPeople(int amount);
	int getPeoples() const { return peoples; }
	void addCar(int amount);
	void subCar(int amount);
	int getCars() const { return cars; }
	void addTruck(int amount);
	void subTruck(int amount);
	int getTrucks() const { return trucks; }
	void addHelicopter(int amount);
	void subHelicopter(int amount);
	int getHelicopters() const { return helicopters; }
	//std::vector<int> selectedResource();
	//const std::unordered_map<std::string, int>& getResources() const { return resources; }
	//const std::unordered_map<std::pair<int, int>, People>& getPeople() const { return peoples; }
	/*void addPeople(int x, int y);
	void subPeople(int x, int y);
	const std::unordered_map<std::pair<int, int>, Car>& getCar() const { return cars; }*/

	//void addCar(int x, int y);
	//void subCar(int x, int y);
	//const std::unordered_map<std::pair<int, int>, Truck>& getTruck() const { return trucks; }
	//void addTruk(int x, int y);
	//void subTruck(int x, int y);
	virtual ~Tile() {}
};
//
//class TileResource : public Tile {
//private:
//    std::string resourceType;
//public:
//	TileResource(int tileNum);
//	std::string getResourceType() { return resourceType; };
//	void addResource( int amount);
//	void subResource(int amount);
//};