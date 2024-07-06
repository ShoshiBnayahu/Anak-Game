#pragma once
#include <iostream>
#include "ReadJson.h"
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
	const int weight = ReadJson::sizes["Tile"][1];
	const int height = ReadJson::sizes["Tile"][0];

	std::unordered_map<std::pair<int, int>, People>peoples;

	std::unordered_map<string, int> resources;



public:
	Tile(int tailNum);
	std::pair<string, int>& getTile() { return tile; };
	std::vector<int> selectedResource();
	const std::unordered_map<std::string, int>& getResources() const {
		return resources;
	}
	const std::unordered_map<std::pair<int, int>, People>& getPeople() const {
		return peoples;
	}
	void addPeople(int x, int y);
	void subPeople(int x, int y);
	virtual ~Tile() {}

};

class TileResource : public Tile {
private:
    std::string resourceType;
public:
	TileResource(int tailNum);
	std::string getResourceType() { return resourceType; };
	//void addResource(int x, int y, int amount);
	void addResource( int amount);
	void subResource(int amount);


};