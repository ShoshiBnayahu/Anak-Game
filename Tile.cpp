#include "Tile.h"
Tile::Tile(int tileNum)
{
	std::string name = ReadJson::tiles[tileNum];
	tile.first = name;
	tile.second = tileNum;
}

void Tile::addPeople(int amount) {
    peoples += amount;
}
void Tile::subPeople(int amount) {
    peoples = std::max(peoples - amount, 0);
}
void Tile::addCar(int amount) {
    cars += amount;
}
void Tile::addTruck(int amount) {
    trucks += amount;
}
void Tile::addHelicopter(int amount) {
    helicopters += amount;
}





