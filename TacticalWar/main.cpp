
#include "IsometricRenderer.h"
#include "BattleScreen.h"
#include <TGUI/TGUI.hpp>

int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tactical War");
	tgui::Gui gui{ window };
	tw::Screen * battle = new tw::BattleScreen(&gui);
	sf::Clock deltaClock;

	while (window.isOpen())
	{
		battle->handleEvents(&window, &gui);
		battle->update(deltaClock.restart().asSeconds());
		window.clear();
		battle->render(&window);
		gui.draw();
		window.display();
	}

	delete battle;

	return 0;
}