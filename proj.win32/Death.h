#ifndef __DEATH_H__
#define __DEATH_H__

#include "cocos2d.h"
#include <stdio.h>

class Death //: public cocos2d::Layer
{
public:
	Death();


	void SetDeath(cocos2d::Layer *layer);

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;

};

#endif //__BALL_H__