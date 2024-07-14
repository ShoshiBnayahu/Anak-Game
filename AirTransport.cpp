#include "AirTransport.h"
int AirTransport::helicopterCounter = 0;

AirTransport::AirTransport(AirTransportType t, std::pair<int, int>l) :Location(l), type(t) {
	if (type == AirTransportType::Helicopter)
		helicopterCounter++;
}

void AirTransport::addResource(std::string resource, int amount)
{
	if (resources.find(resource) != resources.end()) {
		resources[resource] = std::min(resources[resource] + amount, ReadJson::capacities[typeToString(type)][ReadJson::resourceTypes[resource]]);
	}
	else {
		resources[resource] = std::min(amount, ReadJson::capacities[typeToString(type)][ReadJson::resourceTypes[resource]]);
	}
}
std::string  AirTransport::typeToString(AirTransportType type)
{
	switch (type) {
	case AirTransportType::Helicopter:
		return "Helicopter";
	default:
		return "Unknown";
	}
}
int AirTransport::getHelicopterCounter() {
	return helicopterCounter;
}