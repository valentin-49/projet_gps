#include "pch.h"
#include "IsometricRenderer.h"

#include <iostream>

IsometricRenderer::IsometricRenderer(sf::RenderWindow * window)
{
	this->window = window;
}

void IsometricRenderer::render(Environment* environment, std::vector<BaseCharacterModel*> & characters)
{
	// TODO (team "Rendu graphique") : Réaliser le code de dessin de l'environnement (la map) et des personnages dans un repère isométrique.
	// Vous devrez calculer la position des tuiles à l'écran en fonction de leur position dans la grille (dans le tableau 2D)

	sf::RectangleShape rect;
	sf::Color color;
	sf::Vector2f size(64, 64);

	for (int i = 0; i < environment->getWidth(); i++)
	{
		for (int j = 0; j < environment->getHeight(); j++)
		{
			CellData * cell = environment->getMapData(i, j);
			if (cell->getIsObstacle())
			{
				color = sf::Color::Red;
			}
			else if (cell->getIsWalkable())
			{
				color = sf::Color::White;
			}
			else
			{
				color = sf::Color::Black;
			}

			rect.setPosition(i * 64, j * 64);
			rect.setSize(size);
			rect.setFillColor(color);

			window->draw(rect);
		}
	}
}