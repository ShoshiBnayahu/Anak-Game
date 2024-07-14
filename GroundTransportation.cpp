#include "GroundTransportation.h"
//GroundTransportation::GroundTransportation(int x, int y, GroundTransportationType t) :location(std::make_pair(x, y)), type(t) {}
//GroundTransportation::GroundTransportation( GroundTransportationType t) : type(t) {}
int GroundTransportation::carCounter = 0;
int GroundTransportation::truckCounter = 0;
GroundTransportation::GroundTransportation(GroundTransportationType t ,std::pair<int,int>l) :Location(l), type(t) {
	if (type == GroundTransportationType::Car)
		carCounter++;
	else if (type == GroundTransportationType::Truck)
		truckCounter++;
}
void GroundTransportation::addResource(std::string resource, int amount)
{
	if (resources.find(resource) != resources.end()) {
		resources[resource] = std::min(resources[resource] + amount, ReadJson::capacities[typeToString(type)][ReadJson::resourceTypes[resource]]);
	}
	else {
		resources[resource] = std::min(amount, ReadJson::capacities[typeToString(type)][ReadJson::resourceTypes[resource]]);
	}
}
std::string  GroundTransportation::typeToString(GroundTransportationType type)
{
	switch (type) {
	case GroundTransportationType::Car:
		return "Car";
	case GroundTransportationType::Truck:
		return "Truck";
	default:
		return "Unknown";
	}
}
int GroundTransportation::getCarCounter()
{
	return carCounter;
}
int GroundTransportation::getTruckCounter() {
	return truckCounter;
}