#pragma once

#include <map>
#include "CellData.h"

class Environment
{
private:
	int width;
	int height;
	std::map<int, std::map<int, CellData*>> mapData;
	

public:
	Environment(int width, int height);
	CellData* getMapData(int x, int y);
};

