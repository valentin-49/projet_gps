#pragma once

#include "CellColorator.h"

class TestColorator : public tw::CellColorator
{
public:
	virtual sf::Color getColorForCell(tw::CellData * cell);
};

