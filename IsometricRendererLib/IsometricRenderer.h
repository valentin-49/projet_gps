#pragma once

#include <AbstractRenderer.h>
#include <Environment.h>
#include <BaseCharacterModel.h>
#include "CellColorator.h"

#include <vector>
#include <SFML\Graphics.hpp>

namespace tw
{
	class IsometricRenderer : public AbstractRenderer
	{
		sf::RenderWindow * window;
		CellColorator * colorator;

		void manageEvents(Environment * environment, std::vector<BaseCharacterModel*> & characters);

	public:
		IsometricRenderer(sf::RenderWindow * window);
		inline void modifyWindow(sf::RenderWindow * newWindow) { this->window = newWindow; }
		virtual void render(Environment* environment, std::vector<BaseCharacterModel*> & characters);

		void setColorator(CellColorator * colorator)
		{
			this->colorator = colorator;
		}
	};
}