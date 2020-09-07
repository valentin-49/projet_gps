
#include "IsometricRenderer.h"

int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Isometric renderer test module");

	IsometricRenderer renderer(&window);
	Environment environment(20, 20);
	std::vector<BaseCharacterModel*> characters;

	environment.getMapData(2, 2)->setIsObstacle(true);
	environment.getMapData(1, 1)->setIsWalkable(false);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		renderer.render(&environment, characters);
		window.display();
	}

	return 0;
}