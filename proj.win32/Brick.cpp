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
}