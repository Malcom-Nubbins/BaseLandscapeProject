#include "Ball.h"
#include "Define.h"

USING_NS_CC;

Ball::Ball()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	_balls = new CCArray;
	//auto winSize = Director::getInstance()->getVisibleSize();
	//Vec2 origin = Director::getInstance()->getVisibleOrigin();
}

void Ball::SetBall(cocos2d::Layer *layer)
{
	CCLOG("Ball"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
	CCSprite *ball = CCSprite::create("Ball.png");
	//auto ballBounding = PhysicsBody::createCircle(ball->getContentSize().width / 2), (PhysicsMaterial(1.0f, 1.0f, 1.0f));

	auto ballBounding = PhysicsBody::createCircle((10.0f, 10.0f),
		PhysicsMaterial(0.0f, 2.05f, 0.0f));
	ballBounding->setVelocity(Vec2(0, -200));
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


