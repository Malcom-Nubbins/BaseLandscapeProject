//
//  GameManager.h
//  FlappyBird
//
//  Created by Paul Roberts on 28/09/2015.
//	Additions  added by James Edgerton & Joshua Marshall
//

#ifndef GameManager_h
#define GameManager_h

#include <stdio.h>

//-------------------------------------------------------------------------

class GameManager
{

	//-------------------------------------------------------------------------
public:
	~GameManager();
	static GameManager* sharedGameManager();

	//Score accessors.
	void AddToScore(int increment);
	void ResetScore();
	int  GetScore();

	void AddToLives(int incrementlives);
	void ResetLives();
	int  GetLives();

	void AddToLevel(int incrementLevel);
	void ResetLevel();
	int  GetLevel();

	//Accessible variable
	bool isGameLive;

	//-------------------------------------------------------------------------
private:
	GameManager();
	static GameManager* instance;

	int score;
	int lives;
	int level;
};

//-------------------------------------------------------------------------
#endif /* GameManager_h */
