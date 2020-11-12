#pragma once

#include <SFML/Graphics.hpp>
#include <CellData.h>

namespace tw
{
	class CellColorator
	{
	public:
		virtual sf::Color getColorForCell(CellData * cell) = 0;
	};
}