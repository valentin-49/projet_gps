
#include "IsometricRenderer.h"
#include "BattleScreen.h"

int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tactical War");
	tw::Screen * battle = new tw::BattleScreen();
	sf::Clock deltaClock;

	while (window.isOpen())
	{
		battle->handleEvents(&window);
		battle->update(deltaClock.restart().asSeconds());
		window.clear();
		battle->render(&window);
		window.display();
	}

	delete battle;

	return 0;
}