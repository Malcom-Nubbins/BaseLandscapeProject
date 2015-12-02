#include "Player.h"
#include "Define.h"

USING_NS_CC;

Player::Player()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//auto winSize = Director::getInstance()->getVisibleSize();
	//Vec2 origin = Director::getInstance()->getVisibleOrigin();
}

void Player::SetPlayer(cocos2d::Layer *layer)
{
		CCLOG("POWER"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
		auto paddle = Sprite::create("Paddle.png"); // May not need the auto
		auto paddleBounding = PhysicsBody::createBox(paddle->getContentSize());// CHANGE TO CIRCLE PhysicsShapeCircle
		paddleBounding->setDynamic(false);
		paddleBounding->setGravityEnable(true);
		paddle->setPhysicsBody(paddleBounding); //sets a bounding box around brick.
		paddle->setPosition(WinSize.width / 2, WinSize.height / 6);
		layer->addChild(paddle);
}
