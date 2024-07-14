#include "Coordinate.h"
void Coordinate::setObject(ObjectType type, Location * obj) {
 switch (type) {
 case ObjectType::GroundObject:
     groundObject = static_cast<GroundObject*>(obj);
     break;
 case ObjectType::People:
     people = static_cast<People*>(obj);
     break;
 case ObjectType::GroundTransportation:
     groundTransportation = static_cast<GroundTransportation*>(obj);
     break;
 case ObjectType::AirTransport:
     airTransport = static_cast<AirTransport*>(obj);
     break;
 default:
     // Handle invalid type
     break;
 }
}