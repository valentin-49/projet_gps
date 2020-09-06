

#include "Environment.h"
#include "BaseCharacterModel.h"
#include <vector>
#include <IsometricRenderer.h>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
	sf::Window window(sf::VideoMode(800, 600), "Isometric renderer test module");
	
	IsometricRenderer renderer;
	Environment environment(20, 20);
	std::vector<BaseCharacterModel*> characters;

	while (true)
	{
		renderer.render(&environment, characters);
	}

	return 0;
}