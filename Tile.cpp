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
void Tile::subCar(int amount) {
    cars = std::max(cars - amount, 0);
}
void Tile::addTruck(int amount) {
    trucks += amount;
}
void Tile::subTruck(int amount) {
    trucks = std::max(trucks - amount, 0);
}
void Tile::addHelicopter(int amount) {
    helicopters += amount;
}
void Tile::subHelicopter(int amount) {
    helicopters = std::max(helicopters - amount, 0);
}






