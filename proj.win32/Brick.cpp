#include "Brick.h"
#include "Define.h"

USING_NS_CC;

Brick::Brick()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin= Director::getInstance()->getVisibleOrigin();

	//auto winSize = Director::getInstance()->getVisibleSize();
	//Vec2 origin = Director::getInstance()->getVisibleOrigin();
}

void Brick::SetBrick(cocos2d::Layer *layer)
{
	CCLOG("Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT

	auto basicbrick = Sprite::create("White Brick.png"); // May not need the auto
	auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());// sets size of box

	//auto startingBrickPos = () ; //Add Define
	//brickBounding->setDynamic(false);
	basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.

	basicbrick->setPosition(WinSize.width / 2, WinSize.height / 2);
	layer->addChild(basicbrick);
}