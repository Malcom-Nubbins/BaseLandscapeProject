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
	//auto ballBounding = PhysicsBody::createCircle(ball->getContentSize().width / 2), (PhysicsMaterial(1.0f, 1.0f, 1.0f));

	auto ballBounding = PhysicsBody::createCircle((9.0f, 9.0f),
		PhysicsMaterial(0.5f, 2.00f, 0.0f));
	ballBounding->setVelocity(Vec2(cocos2d::random(-500, 500),
		cocos2d::random(-500, 500)));

	ballBounding->setDynamic(true);
	ballBounding->setGravityEnable(false);
	ball->setPhysicsBody(ballBounding); //sets a bounding box around brick.
	ball->setPosition(Vec2(550, 650));
	layer->addChild(ball);
}


