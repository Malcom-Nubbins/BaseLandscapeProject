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

	

	for (int i = 0; i < L1_Brick_NO ; i++)
	{
		if (i % 16 == 0) //CURRENTLY MEANS MUST BE 16 BRICKS ON A LINE. 
		{
			startLine = startLine - 48;
			startPos = 80 ;
		}
		
		CCLOG("Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
		auto basicbrick = Sprite::create("Violet Brick.png"); // May not need the auto
		//basicbrick->setScale(2 .0);
		auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());// sets size of box
		//auto startingBrickPos = () ; //Add Define
		brickBounding->setDynamic(false);
		basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
		startPos = startPos + (Brick_Size + Brick_Distance);
		
		basicbrick->setPosition(Vec2(startPos, startLine));;
		//basicbrick->setPosition(WinSize.width / 16 +StartPos, WinSize.height / 2 + WinSize.height / 3);// could use getPhysicsWorld but requires refractoring
		layer->addChild(basicbrick);
	}
}