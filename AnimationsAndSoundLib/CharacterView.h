#pragma once

#include "pch.h"
#include "AbstractCharacterView.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace tw
{
	class CharacterView : public AbstractCharacterView<sf::Sprite*>
	{
	private:
		sf::Texture testCharacterTexture;
		sf::Sprite testSprite;
		int testOffsetX;
		int testOffsetY;
		
	public:
		CharacterView(BaseCharacterModel * model);
		virtual sf::Sprite * getImageToDraw();
		virtual void update(float deltatime);
	};
}