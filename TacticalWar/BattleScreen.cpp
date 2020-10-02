#include "BattleScreen.h"

using namespace tw;

BattleScreen::BattleScreen()
{
	renderer = new IsometricRenderer(NULL);
	environment = new Environment(20, 20);
	environment->getMapData(2, 2)->setIsObstacle(true);
	environment->getMapData(1, 1)->setIsWalkable(false);
}

void BattleScreen::handleEvents(sf::RenderWindow * window)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void BattleScreen::update(float deltatime)
{

}

void BattleScreen::render(sf::RenderWindow * window)
{
	renderer->modifyWindow(window);
	renderer->render(environment, characters);
}