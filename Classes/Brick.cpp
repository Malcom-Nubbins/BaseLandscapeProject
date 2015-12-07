#include "Brick.h"
#include "Define.h"
#include "physics\CCPhysicsBody.h"

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

	

	for (int i = 0; i < L1_Brick_NO ; i++)
	{

		//miss = miss + L1_Brick_Miss_1 + L1_Brick_Miss_2 + L1_Brick_Miss_4 + L1_Brick_Miss_8 + L1_Brick_Miss_1;
		

		cocos2d::RandomHelper::random_int(1, L1_Brick_NO); //randomises what bricks contain the powerups.

		CCLOG("POWER"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
		auto powerUp = Sprite::create("Extra Life.png"); // May not need the auto
		auto powerUpBounding = PhysicsBody::createCircle(powerUp->getContentSize().width / 2);
		powerUpBounding->setDynamic(false);
		powerUpBounding->setGravityEnable(true);
		powerUp->setPhysicsBody(powerUpBounding); //sets a bounding box around brick.
		powerUp->setPosition(Vec2(500, 600));
		layer->addChild(powerUp);

		//currently all powerups are one ups and currently dont do anything. Have also given them physics for later implementation if there is time.

		if (i % 16 == 0) //CURRENTLY MEANS MUST BE 16 BRICKS ON A LINE. 
		{
			startLine = startLine - 24;
			startPos = 80 ;

		}



		/*if (miss < 0)
		{
			startPos = startPos + 60;
			miss = miss - 1;
		}

		else if (miss >= 0)
		{
			//startPos = startPos + 60;
			miss = miss + 2;
		}
		*/
		else
		{
			//BRICKS COULD BE REFRACTORED TO REDUCE REPEATED CODE
			//if 
			CCLOG("Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
			CCSprite *basicbrick = CCSprite::create("Violet Brick.png");
			//basicbrick->setScale(2 .0);
			auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());// sets size of box
			brickBounding->setCollisionBitmask(1);
			brickBounding->setContactTestBitmask(true);
			//auto startingBrickPos = () ; //Add Define
			brickBounding->setDynamic(false);
			brickBounding->setGravityEnable(false);
			basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
			startPos = startPos + (Brick_Size + Brick_Distance);
			basicbrick->setPosition(Vec2(startPos, startLine));;
			//basicbrick->setPosition(WinSize.width / 16 +StartPos, WinSize.height / 2 + WinSize.height / 3);// could use getPhysicsWorld but requires refractoring
			layer->addChild(basicbrick);
		}


	}
}