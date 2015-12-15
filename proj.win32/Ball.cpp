#include "Ball.h"
#include "Define.h"

USING_NS_CC;

Ball* Ball::instance = NULL;

Ball* Ball::sharedBall()
{
	if (instance == NULL)
	{
		instance = new Ball();
	}

	return instance;
}

Ball::Ball()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	_balls = new CCArray;
}

void Ball::AddToAcceleration(int speed)
{
	this->acceleration += speed;
}

void Ball::ResetAcceleration()
{
	acceleration = 0;
}

void Ball::AddToDampening(float dampening)
{
	this->dampening += dampening;
}

void Ball::ResetDampening()
{
	dampening = 0.0f;
}

void Ball::RemoveBall()
{
	ball->removeChild(ball, true);
}

void Ball::SetBall(cocos2d::Layer *layer,float posX, float posY,int ba)
{
	
	this->x = posX;
	this->y = posY;
	this->amount = ba;

	CCLOG("X %f,Y%f", x,y);
	CCLOG("ba %f", ba);
	CCLOG("AMOUNT %i", amount);
	if (amount <= 0)
	{
		amount == 1;
	}
	for (int q = 0; q < amount; q++)
	{
		acceleration = 0;
		CCLOG("Ball %i",q); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
		ball = CCSprite::create("Ball.png");
		auto ballBounding = PhysicsBody::createCircle((10.0f, 10.0f),
			PhysicsMaterial(1.0f, 2.0f, 0.0f));
		//ballBounding->setVelocity(Vec2(-500, -500)); // 
		//ballBounding->applyForce (Vect(2200, 2200)); 

		int i = cocos2d::RandomHelper::random_int(-5000, 30000);
		int o = cocos2d::RandomHelper::random_int(-5000, 30000);
		ballBounding->applyImpulse(Vect(40000, 58000)); // Dont Understand why the values need to be so high.
		ballBounding->applyTorque(200000); // helps keeps the ball path true. Think spinning a coin
		force = (Vec2(10 + dampening, 10 + dampening));
		ballPos = (Vec2(550, 150));;
		//ballBounding->setCategoryBitmask(0x02);    // 0010
		ballBounding->setContactTestBitmask(true);
		ballBounding->setCollisionBitmask(Ball_Bitmask);
		ballBounding->setCategoryBitmask(1);
		//ballBounding->setContactTestBitmask(0x02);
		//ballBounding->setCollisionBitmask(1);
		//ballBounding->setContactTestBitmask(true);
		ballBounding->setDynamic(true);
		ballBounding->setGravityEnable(false);
		ball->setPhysicsBody(ballBounding); //sets a bounding box around brick.

		if (amount <= 1)
		{
			ball->setPosition(Vec2(550, 150));
		}


		else
		{
			int r = cocos2d::RandomHelper::random_int(-10, 10);

			ball->setPosition(Vec2(x+r, y+r));
		}
		layer->addChild(ball, 2);
		ball->setTag(1);
		//_balls->addObject(ball);
	}
}
