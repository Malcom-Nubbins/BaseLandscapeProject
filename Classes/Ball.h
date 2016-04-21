#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"
#include <stdio.h>

class Ball //: public cocos2d::Layer
{
public:
	Ball();

	static Ball* sharedBall();
	void Update(float dt);

	void SetBall(cocos2d::Layer *layer, float posX, float posY,int ba);

	void AddToAcceleration(int speed);
	void ResetAcceleration();

	void AddToDampening(float dampening);
	void ResetDampening();

	void RemoveBall();

protected:
	cocos2d::Array *_balls;

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;

	cocos2d::Vec2 ballPos;
	cocos2d::Vec2 force;
	cocos2d::Sprite* ball;

	float x;
	float y;
	int amount;
	int rx;
	int ry;
	static Ball* instance;

	int acceleration;
	float dampening;
};

#endif //__BALL_H__