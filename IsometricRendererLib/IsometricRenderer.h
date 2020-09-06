#pragma once

#include "AbstractRenderer.h"
#include "Environment.h"
#include "BaseCharacterModel.h"

#include <vector>
#include <SFML\Graphics.hpp>

class IsometricRenderer : public AbstractRenderer
{
	sf::RenderWindow * window;

public:
	IsometricRenderer(sf::RenderWindow * window);
	virtual void render(Environment* environment, std::vector<BaseCharacterModel*> & characters);
};

