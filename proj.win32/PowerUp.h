#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "cocos2d.h"
#include <stdio.h>

class PowerUp //: public cocos2d::Layer
{
public:
	static PowerUp* sharedPowerUp();
	PowerUp();

	void Update(float dt);
	void SetPowerUp(cocos2d::Layer *layer);
	void SetPowerUpPos(float posX, float posY);

	int a;
	int b;

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;
	cocos2d::Vec2 pos;

	static PowerUp* instance;
};

#endif //__POWERUP_H__