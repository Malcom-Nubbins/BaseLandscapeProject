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
			PhysicsMaterial(1.0f, 1.0f, 0.0f));
		//ballBounding->setVelocity(Vec2(-500, -500)); // 
		//ballBounding->applyForce (Vect(2200, 2200)); 

		int i = cocos2d::RandomHelper::random_int(-5000, 30000);
		int o = cocos2d::RandomHelper::random_int(-5000, 30000);
		//ballBounding->applyImpulse(Vect(40000, 58000)); // Dont Understand why the values need to be so high.
		ballBounding->applyTorque(200000); // helps keeps the ball path true. Think spinning a coin
		Vect velocity(0,-300); 
		ballBounding->setVelocity(velocity);
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
			ball->setPosition(WinSize.width / 2, WinSize.height / 5);
		}


		else
		{
			if (q == 1)
			{
				rx = 0;
				ry = 0;
			}

			else if(q == 2)
			{
				rx = -20;
				ry = +10;
			}

			else if (q == 3)
			{
				rx = +20;
				ry = +10;
			}

			else if (q == 4)
			{
				rx = -30;
				ry = +40;
			}

			else if (q == 5)
			{
				rx = +30;
				ry = +40;
			}

			else if (q == 6)
			{
				rx = -20;
				ry = +60;
			}

			else if (q == 7)
			{
				rx = +20;
				ry = +60;
			}

			else if (q == 8)
			{
				rx = 0;
				ry = +30;
			}

			ball->setPosition(Vec2(x+rx, y+ry));
		}
		layer->addChild(ball, 2);
		ball->setTag(1);
		//_balls->addObject(ball);
	}
}
