//
//  GameManager.h
//  FlappyBird
//
//  Created by Paul Roberts on 28/09/2015.
//	Addtions added by James Edgerton & Joshua Marshall
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

	//Accessible variable
	bool isGameLive;

	//-------------------------------------------------------------------------
private:
	GameManager();
	static GameManager* instance;

	int  score;
};

//-------------------------------------------------------------------------
#endif /* GameManager_h */
