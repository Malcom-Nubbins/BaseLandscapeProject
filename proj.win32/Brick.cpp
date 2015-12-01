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

	//for (int i = 0; i < L1_Brick_NO; i++)
	//{
		//unschedule(schedule_selector(GameScene::SetBrick));
	//}

	auto basicbrick = Sprite::create("White Brick.png"); // May not need the auto
	auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());// sets size of box

	//int inc = basicbrick->getContentSize;

	//auto startingBrickPos = () ; //Add Define
	brickBounding->setDynamic(false);
	basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.

	basicbrick->setPosition(WinSize.width / 2, WinSize.height / 2);// could use getPhysicsWorld but requires refractoring
	layer->addChild(basicbrick);
}