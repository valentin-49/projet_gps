#include "TestColorator.h"

sf::Color TestColorator::getColorForCell(tw::CellData * cell)
{
	if (cell->getX() == 5 && cell->getY() == 4)
	{
		return sf::Color(50, 200, 255);
	}

	return sf::Color(255, 255, 255);
}