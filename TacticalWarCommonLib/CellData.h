#pragma once
class CellData
{
private:
	int x;
	int y;

	bool isWalkable;
	bool isObstacle;

public:
	CellData(int x, int y, bool isWalkable = true, bool isObstacle = false);

	inline int getX() {
		return x;
	}

	inline int getY() {
		return y;
	}

	inline bool getIsWalkable()
	{
		return isWalkable;
	}

	inline bool getIsObstacle()
	{
		return isObstacle;
	}
};

