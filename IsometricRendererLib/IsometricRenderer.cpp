#include "pch.h"
#include "IsometricRenderer.h"
#include <CharacterView.h>

#include <iostream>

using namespace tw;

IsometricRenderer::IsometricRenderer(sf::RenderWindow * window)
{
	this->window = window;
	this->colorator = NULL;
}

void IsometricRenderer::manageEvents(Environment * environment, std::vector<BaseCharacterModel*> & characters)
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		// check the type of the event...
		switch (e.type)
		{
			// window closed
		case sf::Event::Closed:
			window->close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			
			break;

		case sf::Event::MouseButtonPressed:
			if (e.mouseButton.button == sf::Mouse::Left)
			{
				int x = e.mouseButton.x;
				int y = e.mouseButton.y;

				int cellX = x / 64;
				int cellY = y / 64;

				if (cellX >= 0 && cellX < environment->getWidth()
					&&
					cellY >= 0 && cellY < environment->getHeight())
				{
					notifyCellClicked(cellX, cellY);
				}
			}
			break;
			// we don't process other types of events
		default:
			break;
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i position = sf::Mouse::getPosition(*window);
		int cellX = position.x / 64;
		int cellY = position.y / 64;
		if (cellX >= 0 && cellX < environment->getWidth()
			&&
			cellY >= 0 && cellY < environment->getHeight())
		{
			notifyCellMouseDown(cellX, cellY);
		}
	}
}

void IsometricRenderer::test() {

	sf::Texture textureGrass;
	sf::Texture textureWater;
	sf::Texture textureStone;
	sf::Texture textureTree;

	if (!textureGrass.loadFromFile("assets/tiles/Grass_01.png")) { std::cout << "Impossible de charger Grass texture" << std::endl; }
	if (!textureWater.loadFromFile("assets/tiles/Water_01.png")) { std::cout << "Impossible de charger Water texture" << std::endl; }
	if (!textureStone.loadFromFile("assets/tiles/Stone_02.png")) { std::cout << "Impossible de charger Stone texture" << std::endl; }
	if (!textureTree.loadFromFile("assets/tiles/Tree_01.png")) { std::cout << "Impossible de charger Tree texture" << std::endl; }


}

void IsometricRenderer::render(Environment* environment, std::vector<BaseCharacterModel*> & characters, float deltatime)
{
	manageEvents(environment, characters);
	// TODO (team "Rendu graphique") : Réaliser le code de dessin de l'environnement (la map) et des personnages dans un repère isométrique.
	// Vous devrez calculer la position des tuiles à l'écran en fonction de leur position dans la grille (dans le tableau 2D)

	sf::Texture textureGrass;
	sf::Texture textureWater;
	sf::Texture textureStone;
	sf::Texture textureTree;


		if (!textureGrass.loadFromFile("assets/tiles/Grass_0.png")) { std::cout << "Impossible de charger Grass texture" << std::endl; }

	
	//if (!textureWater.loadFromFile("assets/tiles/Water_01.png")) { std::cout << "Impossible de charger Water texture" << std::endl; }
	//if (!textureStone.loadFromFile("assets/tiles/Stone_02.png")) { std::cout << "Impossible de charger Stone texture" << std::endl; }
	//if (!textureTree.loadFromFile("assets/tiles/Tree_01.png")) { std::cout << "Impossible de charger Tree texture" << std::endl; }
	
	sf::Sprite spriteGrass;
	sf::Sprite spriteStone;
	sf::Sprite spriteWater;
	sf::Sprite spriteTree;
	sf::Sprite spriteToDraw;
	
	//sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	spriteGrass.setTexture(textureGrass);
	spriteWater.setTexture(textureWater);
	spriteStone.setTexture(textureStone);
	spriteTree.setTexture(textureTree);
	
	

	spriteGrass.setPosition(0, 0);
	spriteGrass.setScale(0.05, 0.05);


	sf::RectangleShape rect;
	sf::Color color;
	sf::Vector2f size(32, 32);
	/*
	for (int i = 0; i < environment->getWidth(); i++)
	{
		for (int j = 0; j < environment->getHeight(); j++)
		{
			CellData * cell = environment->getMapData(i, j);
			if (cell->getIsObstacle())
			{
				//color = sf::Color::Red;
				//spriteToDraw = spriteStone;

			}
			else if (cell->getIsWalkable())
			{
				//color = sf::Color::White;
				//spriteToDraw = spriteGrass;
			}
			else
			{

				//color = sf::Color::Black;
				//spriteToDraw = spriteWater;
			}
			spriteToDraw = spriteGrass;
			spriteToDraw.setPosition(i*120, j*60); 
			spriteToDraw.setScale(0.05, 0.05);
			//sprite.setSize(size);

			/*sf::Color mulColor = sf::Color::White;
			if (colorator != NULL)
			{
				mulColor = colorator->getColorForCell(cell);
			}

			rect.setFillColor(color * mulColor);
			*/
			
			window->draw(spriteGrass);
		//}
	//}
	/*
	for (int i = 0; i < characters.size(); i++)
	{
		BaseCharacterModel * m = characters[i];
		CharacterView & v = getCharacterView(m);
		v.update(deltatime);
		sf::Sprite * s = v.getImageToDraw();
		s->setPosition(m->getInterpolatedX() * 64, m->getInterpolatedY() * 64);
	

		sf::IntRect rect = s->getTextureRect();
		float scaleX = 64.0 / (float)rect.width;
		float scaleY = 64.0 / (float)rect.height;
		s->setScale(scaleX, scaleY);
		window->draw(*s);
	}*/
}


CharacterView & IsometricRenderer::getCharacterView(BaseCharacterModel * model)
{
	if (characterViewsCache.find(model) == characterViewsCache.end())
	{
		characterViewsCache[model] = new CharacterView(model);
	}

	return *characterViewsCache[model];
}