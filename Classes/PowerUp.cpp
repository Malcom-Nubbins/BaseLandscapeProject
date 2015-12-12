#include "PowerUp.h"
#include "Define.h"

USING_NS_CC;

PowerUp::PowerUp()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void PowerUp::SetPowerUp(cocos2d::Layer *layer)
{
	for (int i = 1; i < 1; i++)
	{
		auto powerUp = Sprite::create("Extra Life.png"); // May not need the auto
		auto powerUpBounding = PhysicsBody::createCircle((10.0f, 10.0f),
			PhysicsMaterial(1.0f, 2.0f, 0.0f));
		a = cocos2d::RandomHelper::random_int(-12000, 12000);
		b = cocos2d::RandomHelper::random_int(8000, 10000);
		//powerUpBounding->setVelocity(Vec2(a, b)); // 
		powerUpBounding->applyImpulse(Vec2(a, b));
		powerUpBounding->applyTorque(12000);
		powerUpBounding->applyForce(Vect(a, b));
		powerUpBounding->setDynamic(true);
		powerUpBounding->setGravityEnable(true);
		powerUpBounding->setContactTestBitmask(true);
		powerUpBounding->setCategoryBitmask(1);
		powerUpBounding->setCollisionBitmask(PowerUp_Bitmask);
		powerUp->setPhysicsBody(powerUpBounding); //sets a bounding box around brick.
		powerUp->setPosition(Vec2(200, 600));
		layer->addChild(powerUp);
	}
}
