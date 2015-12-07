#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"

class Ball //: public cocos2d::Layer
{
public:
	Ball();

	void SetBall(cocos2d::Layer *layer);

protected:
	cocos2d::CCArray *_balls;

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;
};

#endif //__BALL_H__