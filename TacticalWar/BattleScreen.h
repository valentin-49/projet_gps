#pragma once

#include "Screen.h"
#include <IsometricRenderer.h>
#include <Environment.h>
#include <BaseCharacterModel.h>

namespace tw
{
	class BattleScreen : public Screen
	{
	private:
		IsometricRenderer * renderer;
		Environment * environment;
		std::vector<tw::BaseCharacterModel*> characters;

	public:
		BattleScreen();

		virtual void handleEvents(sf::RenderWindow * window);
		virtual void update(float deltatime);
		virtual void render(sf::RenderWindow * window);
	};
}

