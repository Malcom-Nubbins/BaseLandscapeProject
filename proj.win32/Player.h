#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include <stdio.h>

class Player //: public cocos2d::Layer
{
public:
	Player();

	void SetPlayer(cocos2d::Layer *layer);
	void SetPlayerPos(float x, float y);
	float GetPlayerPosX();
	void RemovePlayer();

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* paddle;
	float paddlePos;
};

#endif //__PLAYER_H__