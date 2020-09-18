#pragma once
#include "Point2D.h"

namespace tw
{
	class CellData : public Point2D
	{
	private:
		bool isWalkable;
		bool isObstacle;

	public:
		CellData(int x, int y, bool isWalkable = true, bool isObstacle = false);


		inline bool getIsWalkable()
		{
			return isWalkable;
		}

		inline void setIsWalkable(bool isWalkable) {
			this->isWalkable = isWalkable;
		}

		inline bool getIsObstacle()
		{
			return isObstacle;
		}

		inline void setIsObstacle(bool isObstacle) {
			this->isObstacle = isObstacle;
		}
	};
}

