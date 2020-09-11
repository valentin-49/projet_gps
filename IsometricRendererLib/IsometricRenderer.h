#pragma once

#include "AbstractRenderer.h"
#include "Environment.h"
#include "BaseCharacterModel.h"

#include <vector>
#include <SFML\Graphics.hpp>

namespace tw
{
	class IsometricRenderer : public AbstractRenderer
	{
		sf::RenderWindow * window;

		void manageEvents(Environment * environment, std::vector<BaseCharacterModel*> & characters);

	public:
		IsometricRenderer(sf::RenderWindow * window);
		virtual void render(Environment* environment, std::vector<BaseCharacterModel*> & characters);
	};
}