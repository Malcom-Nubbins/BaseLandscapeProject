#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"

class Ball //: public cocos2d::Layer
{
public:
	Ball();
	void Update(float dt);

	void SetBall(cocos2d::Layer *layer);
	int acceleration;

protected:
	cocos2d::CCArray *_balls;

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;

	cocos2d::Vec2 ballPos;
	cocos2d::Vec2 force;

	void Rotate(float i);
};

#endif //__BALL_H__