#include "PowerUp.h"
#include "Define.h"

USING_NS_CC;

PowerUp* PowerUp::instance = NULL;

PowerUp* PowerUp::sharedPowerUp()
{
	if (instance == NULL)
	{
		instance = new PowerUp();
	}

	return instance;
}

PowerUp::PowerUp()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

}


void PowerUp::SetPowerUpPos(float posX, float posY)
{

}

void PowerUp::SetPowerUp(cocos2d::Layer *layer, float posX, float posY)
{		
	
	int i = cocos2d::RandomHelper::random_int(3, 3); //set this to everytime for testing purposes

	//CCLOG("I: %i", i);
	this->x = posX;
	this->y = posY;

	if (i == 1 || i == 2) //life Up
	{
		auto LifeUp = Sprite::create("Extra Life.png"); // May not need the auto
		auto LifeUpBounding = PhysicsBody::createCircle((10.0f, 10.0f),
			PhysicsMaterial(1.0f, 2.0f, 0.0f));
		a = cocos2d::RandomHelper::random_int(-12000, 12000);
		b = cocos2d::RandomHelper::random_int(8000, 10000);
		//powerUpBounding->setVelocity(Vec2(a, b)); // 
		LifeUpBounding->applyImpulse(Vec2(a, b));
		LifeUpBounding->applyTorque(12000);
		LifeUpBounding->applyForce(Vect(a, b));
		LifeUpBounding->setDynamic(true);
		LifeUpBounding->setGravityEnable(true);
		LifeUpBounding->setContactTestBitmask(true);
		LifeUpBounding->setCategoryBitmask(1);
		LifeUpBounding->setCollisionBitmask(LiveUp_Bitmask);
		LifeUp->setPhysicsBody(LifeUpBounding);
		LifeUp->setPosition(Vec2(x, y));
		layer->addChild(LifeUp);
		LifeUp->setZOrder(1);
	}

	
	else if (i == 3 || i == 4 || i == 5 || i == 6)// Ball Split
	{
		auto two = Sprite::create("MultiBall Two.png"); // May not need the auto
		auto twoBounding = PhysicsBody::createCircle((10.0f, 10.0f),
			PhysicsMaterial(1.0f, 2.0f, 0.0f));
		a = cocos2d::RandomHelper::random_int(-12000, 12000);
		b = cocos2d::RandomHelper::random_int(8000, 10000);
		//powerUpBounding->setVelocity(Vec2(a, b)); // 
		twoBounding->applyImpulse(Vec2(a, b));
		twoBounding->applyTorque(12000);
		twoBounding->applyForce(Vect(a, b));
		twoBounding->setDynamic(true);
		twoBounding->setGravityEnable(true);
		twoBounding->setContactTestBitmask(true);
		twoBounding->setCategoryBitmask(1);
		twoBounding->setCollisionBitmask(TwoSplit_Bitmask);
		two->setPhysicsBody(twoBounding);
		two->setPosition(Vec2(x, y));
		layer->addChild(two);
		two->setZOrder(1);
	}

	else if (i == 7 || i == 8 || i == 9)// Three Way (Imagine the chance to disappoint two women at once.)
	{
		auto three= Sprite::create("MultiBall Three.png"); // May not need the auto
		auto threeBounding = PhysicsBody::createCircle((10.0f, 10.0f),
			PhysicsMaterial(1.0f, 2.0f, 0.0f));
		a = cocos2d::RandomHelper::random_int(-12000, 12000);
		b = cocos2d::RandomHelper::random_int(8000, 10000);
		//powerUpBounding->setVelocity(Vec2(a, b)); // 
		threeBounding->applyImpulse(Vec2(a, b));
		threeBounding->applyTorque(12000);
		threeBounding->applyForce(Vect(a, b));
		threeBounding->setDynamic(true);
		threeBounding->setGravityEnable(true);
		threeBounding->setContactTestBitmask(true);
		threeBounding->setCategoryBitmask(1);
		threeBounding->setCollisionBitmask(ThreeSplit_Bitmask);
		three->setPhysicsBody(threeBounding);
		three->setPosition(Vec2(x, y));
		layer->addChild(three);
		three->setZOrder(1);
	}

	else if (i == 10)// Nine Way!
	{
		auto nine = Sprite::create("MultiBall Nine.png"); // May not need the auto
		auto nineBounding = PhysicsBody::createCircle((10.0f, 10.0f),
			PhysicsMaterial(1.0f, 2.0f, 0.0f));
		a = cocos2d::RandomHelper::random_int(-12000, 12000);
		b = cocos2d::RandomHelper::random_int(8000, 10000);
		//powerUpBounding->setVelocity(Vec2(a, b)); // 
		nineBounding->applyImpulse(Vec2(a, b));
		nineBounding->applyTorque(12000);
		nineBounding->applyForce(Vect(a, b));
		nineBounding->setDynamic(true);
		nineBounding->setGravityEnable(true);
		nineBounding->setContactTestBitmask(true);
		nineBounding->setCategoryBitmask(1);
		nineBounding->setCollisionBitmask(NineSplit_Bitmask);
		nine->setPhysicsBody(nineBounding); //sets a bounding box around brick.
		nine->setPosition(Vec2(x, y));
		layer->addChild(nine);
		nine->setZOrder(1);
	}
}
