#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

class Player //: public cocos2d::Layer
{
public:
	Player();

	void SetPlayer(cocos2d::Layer *layer);
	void GetPlayerPosX();

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;
};

#endif //__PLAYER_H__