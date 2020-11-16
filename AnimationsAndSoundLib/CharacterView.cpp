#include "pch.h"
#include "CharacterView.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace tw;
using namespace std;
std::map<std::string, sf::Texture*> * CharacterView::textureCache = NULL;

sf::Texture* CharacterView::getCachedTexture(std::string path)
{
	if (textureCache == NULL)
		textureCache = new std::map<std::string, sf::Texture*>();

	sf::Texture *texture;
	if (textureCache->find(path) != textureCache->end())
	{
		texture = (*textureCache)[path];
	}
	else
	{
		texture = new sf::Texture();
		texture->loadFromFile(path);
		(*textureCache)[path] = texture;
	}

	return texture;
}

CharacterView::CharacterView(BaseCharacterModel * model)
	: AbstractCharacterView<sf::Sprite*>(model)
{
	orientation = Orientation::BOTTOM_RIGHT;
	animationsMap[Orientation::BOTTOM_RIGHT][Animation::RUN] = loadAnimation(model->getGraphicsPath() + "bottomright-sheet");

}

std::vector<sf::Sprite*> CharacterView::loadAnimation(std::string filename)
{
	std::vector<sf::Sprite *> anim;
	
	int tabs[6] = { 0 };
	char lignes[600] = { 0 }, ligneset[30][60] = { 0 };
	double NbImg = -1;

	sf::Texture *testCharacterTexture = getCachedTexture(filename + ".png");
	int testOffsetX;
	int testOffsetY;

	ifstream position(filename + ".anim.exode", ios::in);
	if (position)
		position.get(lignes, 600, '/n');  // tant que l'on peut mettre la ligne dans "contenu"	
	int x = 0, z = 0;
	for (int y = 0; y < strlen(lignes); y++) {
		if (lignes[y] != '\n') {

			ligneset[z][x] = lignes[y];
			x++;
		}
		else {
			z++; x = 0;
		}
	}
	for (int y = 0; y < 15; y++) {
		if (ligneset[y][0] != '\0') {
			NbImg++;
		}
		else
			y = 15;
	}

	testCharacterTexture->setSmooth(true);

	
	for (int i = 0; i < NbImg; i++)
	{
		char tab[40] = { 0 };
		int b = 0;
		std::vector<int> myvector;
		for (int y = 0; y < strlen(ligneset[i]); y++) {
			if (ligneset[i][y] != ';') {
				tab[b] = ligneset[i][y];
				b++;
			}
			else {
				myvector.push_back(atof(tab));
				for (int o = 0; o < 5; o++)
					tab[o] = { 0 };
				b = 0;
			}
		}
		if (tab[0] != '\0') {
			myvector.push_back(atof(tab));
		}
		int sum = 0;
		while (!myvector.empty())
		{
			tabs[sum] = myvector.back();
			myvector.pop_back();
			sum++;
		}
		
		sf::Sprite * s = new sf::Sprite(*testCharacterTexture, sf::IntRect(tabs[5], tabs[4], tabs[3], tabs[2]));
		//s->setScale(-1, 1);
		testOffsetX = tabs[1];
		testOffsetY = tabs[0];
		//s->setOrigin(testOffsetX, testOffsetY);
		anim.push_back(s);
	}

	return anim;
}

CharacterView::~CharacterView()
{
	//delete testCharacterTexture;
}

sf::Sprite* CharacterView::getImageToDraw()
{
	// TODO : (team "Animation personnage") : Réaliser le code d'animation du personnage dans cette classe.
	// Cette méthode (getImageToDraw) doit retourner l'image qui devra être dessinée à l'écran (en fonction de où en est l'animation)
	// Vous devrez également utiliser les services de la team "Colorisation" pour obtenir un personnage coloré (personnalisation des couleurs en fonction de l'équipe).
	
	double p = 1, time = elsetime;

	int nbImg = animationsMap[orientation][Animation::RUN].size();
	p /= nbImg;
	int index;
	index = fmod(time / p, nbImg);
	return animationsMap[orientation][Animation::RUN][index];
}

void CharacterView::update(float deltatime)
{
	elsetime += deltatime;
}