#include "Ball.h"
#include "Define.h"

USING_NS_CC;

Ball::Ball()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//auto winSize = Director::getInstance()->getVisibleSize();
	//Vec2 origin = Director::getInstance()->getVisibleOrigin();
}

void Ball::SetBall(cocos2d::Layer *layer)
{
	CCLOG("POWER"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
	auto ball = Sprite::create("Ball.png"); // May not need the auto
	auto ballBounding = PhysicsBody::createBox(ball->getContentSize());// CHANGE TO CIRCLE PhysicsShapeCircle
	//ballBounding->setDynamic(false);
	//ballBounding->setGravityEnable(true);
	ball->setPhysicsBody(ballBounding); //sets a bounding box around brick.
	ball->setPosition(Vec2(550, 650));
	layer->addChild(ball);
}
