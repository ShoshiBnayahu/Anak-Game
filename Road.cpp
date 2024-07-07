#include "Road.h"
int Road::roadCounter = 0;

Road::Road(int x, int y, GroundObjectType type, bool isComplate) : GroundObject(x, y, type, isComplate)
{
	roadCounter++;
}

