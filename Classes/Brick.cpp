#include "Brick.h"
#include "Define.h"
#include "physics\CCPhysicsBody.h"

USING_NS_CC;

Brick::~Brick()
{
	
}

Brick::Brick()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin= Director::getInstance()->getVisibleOrigin();

	cocos2d::CCArray *_bricks;
	this->_bricks = CCArray::createWithCapacity(L1_Brick_NO);
	this->_bricks->retain();
}



bool Brick::init()
{
	return true;
}
void Brick::SetBrick(cocos2d::Layer *layer)
	
{

	bricks = 0;
	blocks = 0;
	lines = 0;
	inc = 1;
	type = 0;
	level = 1;
	__String spawn = "1";

	__String *file = __String::createWithFormat("level%i.plist",level); // allows mutiple level .plists
	__Dictionary *list = __Dictionary::createWithContentsOfFile(file->getCString()); //makes a list with all the data
	__String *Bricks = __String::create(list->valueForKey("Bricks")->getCString()); //assiging a key.
	__String *Lines = __String::create(list->valueForKey("Lines")->getCString());

	 bricks = Bricks->intValue();
	 lines = Lines->intValue();

	 CCLOG("level: %i", level);
	 CCLOG("Bricks: %i", bricks);
	 CCLOG("Lines: %i", lines);

	 for (int i = 0; i < bricks; i++)
	 {

		 __String *spawn = __String::createWithFormat("%d", inc);

		
		 //Block = list->valueForKey(spawn ->get)

		__String *Block = __String::createWithFormat(list->valueForKey("1")->getCString());

		 blocks = Block->intValue();
		 CCLOG("block: %i", blocks);
		 inc = inc + 1;
	 }


	 for (int i = 0; i < bricks; i++)
	{
		cocos2d::RandomHelper::random_int(1, L1_Brick_NO); //randomises what bricks contain the powerups.
		//CCLOG("POWER"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
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

		else
		{
			//BRICKS COULD BE REFRACTORED TO REDUCE REPEATED CODE
			//if 
			//CCLOG("Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
			CCSprite *basicbrick = CCSprite::create("Violet Brick.png");
			this->_bricks->addObject(basicbrick);
			//basicbrick->setScale(2 .0);
			auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
			brickBounding->setCollisionBitmask(1);
			brickBounding->setContactTestBitmask(true);
			brickBounding->setDynamic(false);
			brickBounding->setGravityEnable(true);
			basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
			startPos = startPos + (Brick_Size + Brick_Distance);
			basicbrick->setPosition(Vec2(startPos, startLine));;
			layer->addChild(basicbrick, 1);
			//basicbrick->setTag(i);
			//_bricks->addObject(basicbrick);

			
		}
	}
}

void Brick::RemoveBrick(cocos2d::Layer *layer)
{
	
	layer->removeChildByTag(4, true);
}
