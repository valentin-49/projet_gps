#pragma once

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

namespace tw
{
	class Screen
	{
	public:
		Screen();
		virtual void handleEvents(sf::RenderWindow * window, tgui::Gui * gui) = 0;
		virtual void update(float deltatime) = 0;
		virtual void render(sf::RenderWindow * window) = 0;
	};
}