#pragma once
#include "Environment.h"

class BaseCharacterModel
{
private:
	Environment* environment;

	int teamId;

	int currentX;
	int currentY;

	int currentLife;


public:
	BaseCharacterModel(Environment* environment, int teamId, int currentX, int currentY);


	virtual int getClassId() = 0;

	// Retourne la valeur du maximum de point de vie de base (sans altération d'effet). C'est une caractéristique de base de la classe.
	virtual int getBaseMaxLife() = 0;
	virtual bool doAttack1(int targetX, int targetY) = 0;
	virtual bool doAttack2(int targetX, int targetY) = 0;
	virtual bool doAttack3(int targetX, int targetY) = 0;
	virtual bool doAttack4(int targetX, int targetY) = 0;
	
	inline int getTeamId() {
		return teamId;
	}
	
	inline int getCurrentX() {
		return currentX;
	}

	inline int getCurrentY() {
		return currentY;
	}

	inline Environment* getEnvironment()
	{
		return environment;
	}

	inline int getCurrentLife()
	{
		return currentLife;
	}
};

