#pragma once

#include <SFML/Graphics.hpp>

namespace tw
{
	class Screen
	{
	public:
		Screen();
		virtual void handleEvents(sf::RenderWindow * window) = 0;
		virtual void update(float deltatime) = 0;
		virtual void render(sf::RenderWindow * window) = 0;
	};
}