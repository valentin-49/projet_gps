#pragma once

#include <map>
#include "CellData.h"

namespace tw
{
	class Environment
	{
	private:
		int width;
		int height;
		std::map<int, std::map<int, CellData*>> mapData;

		int id;

	public:
		Environment(int width, int height, int environmentId);
		CellData* getMapData(int x, int y);

		inline int getWidth() { return width; }
		inline int getHeight() { return height; }

		inline int getId() { return id; }
	};
}

