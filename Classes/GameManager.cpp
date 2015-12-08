//
//  GameManager.cpp
//  FlappyBird
//
//  Created by Paul Roberts on 28/09/2015.
//  Addtions added by James Edgerton & Joshua Marshall
//

#include "GameManager.h"

//Set the instance to be null.
GameManager* GameManager::instance = NULL;

//-------------------------------------------------------------------------

GameManager* GameManager::sharedGameManager()
{
	if (instance == NULL)
	{
		instance = new GameManager();
	}

	return instance;
}

//-------------------------------------------------------------------------

GameManager::GameManager()
{
	isGameLive = false;
	score = 0;
}

//-------------------------------------------------------------------------

GameManager::~GameManager()
{

}

//-------------------------------------------------------------------------

void GameManager::AddToScore(int increment)
{
	this->score += increment;
}

//-------------------------------------------------------------------------

void GameManager::ResetScore()
{
	score = 0;
}

//-------------------------------------------------------------------------

int GameManager::GetScore()
{
	return score;
}

//-------------------------------------------------------------------------

