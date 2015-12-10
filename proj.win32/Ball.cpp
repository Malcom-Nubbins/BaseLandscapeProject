#include "Ball.h"
#include "Define.h"

USING_NS_CC;

Ball::Ball()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	_balls = new CCArray;
}

void Ball::AddToAcceleration(int speed)
{
	this->acceleration += speed;
}

void Ball::ResetAcceleration()
{
	acceleration = 0;
}



void Ball::SetBall(cocos2d::Layer *layer)
{
	acceleration = 0;
	CCLOG("Ball"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
	CCSprite *ball = CCSprite::create("Ball.png");
	auto ballBounding = PhysicsBody::createCircle((10.0f, 10.0f),
		PhysicsMaterial(1.0f, 2.0f, 0.0f));
	//ballBounding->setVelocity(Vec2(-500, -500)); // 
	//ballBounding->applyForce (Vect(2200, 2200)); 
	ballBounding->applyImpulse(Vect(50000 + acceleration, 68000 + acceleration)); // Dont Understand why the values need to be so high.
	ballBounding->applyTorque(200000); // helps keeps the ball path true. Think spinning a coin
	force = (Vec2(10, 10));
	ballPos = (Vec2(550, 150));;
	ballBounding->setCollisionBitmask(2);
	ballBounding->setContactTestBitmask(true);
	ballBounding->setDynamic(true);
	ballBounding->setGravityEnable(false);
	ball->setPhysicsBody(ballBounding); //sets a bounding box around brick.
	ball->setPosition(Vec2(550, 150));
	layer->addChild(ball ,2);
	ball->setTag(1);
	//_balls->addObject(ball);
}
