#include "pch.h"
#include "BaseCharacterModel.h"

BaseCharacterModel::BaseCharacterModel(Environment* environment, int teamId, int currentX, int currentY)
{
	this->teamId = teamId;
	this->environment = environment;
	this->currentX = currentX;
	this->currentY = currentY;
}

BaseCharacterModel::~BaseCharacterModel()
{

}