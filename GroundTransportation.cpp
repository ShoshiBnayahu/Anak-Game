#include "GroundTransportation.h"
//GroundTransportation::GroundTransportation(int x, int y, GroundTransportationType t) :location(std::make_pair(x, y)), type(t) {}
//GroundTransportation::GroundTransportation( GroundTransportationType t) : type(t) {}


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