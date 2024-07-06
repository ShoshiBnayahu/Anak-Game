#pragma once
#include "GroundObject.h"

class Road : public GroundObject
{
private:
	static int roadCounter;

public:
	Road(int x, int y, GroundObjectType type, bool isComplate) : GroundObject(x, y, type, isComplate)
		{
			roadCounter++;
		}
		static int getRoadCounter() {
			return roadCounter;
		}
	void makeEmpty()override{}
};

