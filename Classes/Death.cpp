#include "Death.h"
#include "Define.h"

USING_NS_CC;

Death::Death()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

}

void Death::SetDeath(cocos2d::Layer *layer)
{
	CCSprite *die = CCSprite::create();
	auto death = PhysicsBody::createBox(Size(WinSize.width, WinSize.height/7));
	death->setDynamic(false);
	death->setGravityEnable(false);
	
	//ballBounding->setContactTestBitmask(0x02);
	//ballBounding->setCollisionBitmask(1);
	//ballBounding->setContactTestBitmask(true);
	die->setPhysicsBody(death); //sets a bounding box around brick.
	die->setPosition(WinSize.width / 2 + origin.x, WinSize.height / 13 + origin.y);
	layer->addChild(die);
	//_balls->addObject(ball);
}
