#pragma once
#include <iostream>
#include "ReadJson.h"
#include "Resource.h"
#include "People.h"

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


class Tile
{
protected:

	std::pair<std::string, int> tile;
	//x
	const int weight= ReadJson::SizeOfTiles[1];
	//y
	const int height = ReadJson::SizeOfTiles[0];

	std::unordered_map<std::pair<int, int>, People> peoples;


    


public:
	Tile(int tailNum);
	std::pair<string, int>& getTile() { return tile; };
};

class TileResource : public Tile {
private:
    std::unordered_map<std::pair<int, int>, Resource> resources;
    std::string resourceType;


public:
	TileResource(int tailNum);

	std::string getResourceType() { return resourceType; };

	void addResource(int x, int y, int amount);

   
};