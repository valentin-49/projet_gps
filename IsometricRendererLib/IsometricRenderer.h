#pragma once

#include "AbstractRenderer.h"
#include "Environment.h"
#include "BaseCharacterModel.h"

#include <vector>

class IsometricRenderer : public AbstractRenderer
{
public:
	virtual void render(Environment* environment, std::vector<BaseCharacterModel*> & characters);
};

