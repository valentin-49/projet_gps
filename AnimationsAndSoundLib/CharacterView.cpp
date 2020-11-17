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
	sf::Texture *testCharacterTexture = getCachedTexture(filename + ".png");
	ifstream position(filename + ".anim.exode", ios::in);
	string str;
	double NbImg = -1;
	int testOffsetX, testOffsetY;

	if (position){
		while (getline(position, str))
		positionView.push_back(str);	// tant que l'on peut mettre la ligne dans "positionView"	
	} 	
	for (int y = 0; y < positionView.size(); y++) {		// compte le nombre d'imagne dans le fichier
		if (positionView[y][0] != '\0')
			NbImg++;	
	}

	testCharacterTexture->setSmooth(true);
	// modifier le code pour qui sois un peut plus simple.
	for (int i = 0; i < NbImg; i++)
	{
		int b = 0;
		for (int y = 0; y < positionView[i].length(); y++) {
			if (positionView[i][y] != ';') {
				positionViewTrie[b] = positionView[i][y];
				b++;
			}
			else {
				//a fini!!
				positionViewInt.push_back(atoi(positionViewTrie.front()));
				positionViewTrie.clear();
				b = 0;
			}
		}
		if (tab[0] != '\0') {
			positionViewInt.push_back(atof(tab));
		}
		sf::Sprite * s = new sf::Sprite(*testCharacterTexture, sf::IntRect(positionViewInt[0], positionViewInt[1], positionViewInt[2], positionViewInt[3]));
		testOffsetX = positionViewInt[4];
		testOffsetY = positionViewInt[5];
		//s->setOrigin(testOffsetX, testOffsetY);
		anim.push_back(s);
		positionViewInt.clear();
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