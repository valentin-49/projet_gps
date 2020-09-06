#pragma once

#include "pch.h"
#include "AbstractCharacterView.h"
#include <SFML/Graphics/Sprite.hpp>
class CharacterView : public AbstractCharacterView<sf::Sprite*>
{
public:
	virtual sf::Sprite * getImageToDraw();
	virtual void update(float deltatime);
};

