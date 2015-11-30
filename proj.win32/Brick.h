#ifndef __BRICK_H__
#define __BRICK_H__

#include "cocos2d.h"

class Brick //: public cocos2d::Layer
{
public:
	Brick();

	void SetBrick(cocos2d::Layer *layer);

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;
};

#endif //__BRICK_H__