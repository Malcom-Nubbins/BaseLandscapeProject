#include "Brick.h"
#include "Define.h"
#include "physics\CCPhysicsBody.h"

USING_NS_CC;

Brick* Brick::instance = NULL;

Brick* Brick::sharedBrick()
{
	if (instance == NULL)
	{
		instance = new Brick();
	}

	return instance;
}

Brick::~Brick()
{
	
}

Brick::Brick()
{
	WinSize = Director::getInstance()->getVisibleSize();
	origin= Director::getInstance()->getVisibleOrigin();

	cocos2d::Array *_bricks;
	this->_bricks = Array::createWithCapacity(L1_Brick_NO);
	this->_bricks->retain();

	
}

void Brick::SetLevel(int level)
{
	this->level = level;
}

bool Brick::init()
{
	return true;
}
void Brick::SetBrick(cocos2d::Layer *layer, int level)	// Level 2 gives different block layout //so does level 3 YEAHHHHHH!!!!!! I May be drunk while typing this.
	
{

	//CCLOG("level: %i", level);
	this->level = level;
	bricks = 0;
	//blocks = 0;
	lines = 0;
	inc = 1;
	type = 1;
	startPos = 140;
	startLine = 576;
	__String spawn = "1";
	
	std::string file = StringUtils::format("level %d.plist", level); // allows mutiple level .plists
	__Dictionary* list = __Dictionary::createWithContentsOfFile(file.c_str()); //makes a list with all the data
	std::string bricksStr = StringUtils::format("%s", list->valueForKey("Bricks")->getCString());
	std::string linesStr = StringUtils::format("%s", list->valueForKey("Lines")->getCString());
	//__String *Bricks = __String::create(list->valueForKey("Bricks")->getCString()); //assiging a key.
	//__String *Lines = __String::create(list->valueForKey("Lines")->getCString());

	bricks = strtod(bricksStr.c_str(), nullptr);
	lines = strtod(linesStr.c_str(), nullptr);


	 for (int i = 1; i < bricks; i++)
	 {
		 std::string blockStr = list->valueForKey(StringUtils::format("%d", i))->getCString();
		 blocks = strtod(blockStr.c_str(), nullptr);
		 std::string typeStr = list->valueForKey(StringUtils::format("%db", i))->getCString();
		 type = strtod(typeStr.c_str(), nullptr);
		
		 if (blocks == 0 || blocks == 1)
		 {
			 if (type == 1)
			 {
				 CCLOG("Violet Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Violet Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 2)
			 {
				 CCLOG("Yellow Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Yellow Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 3)
			 {
				 CCLOG(" Orange Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Orange Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 4)
			 {
				 CCLOG("Cyan Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Cyan Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 5)
			 {
				 CCLOG("Green Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Green Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 6)
			 {
				 CCLOG("Blue Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Blue Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				// brickBounding->setCollisionBitmask(1);
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 7)
			 {
				 CCLOG("Purple Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Purple Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 8)
			 {
				 CCLOG("Red Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Red Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 14)
			 {
				 CCLOG("White Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("White Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 10)
			 {
				 CCLOG("Grey Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Grey Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 11)
			 {
				 CCLOG("Black Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Black Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 12)
			 {
				 CCLOG("Amber Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Amber Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 13)
			 {
				 CCLOG("Dakota Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Dakota Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 else if (type == 9)
			 {
				 CCLOG("Blue Grey Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 Sprite *basicbrick = Sprite::create("Blue Grey Brick.png");
				 this->_bricks->addObject(basicbrick);
				 //basicbrick->setScale(2 .0);
				 auto brickBounding = PhysicsBody::createBox(basicbrick->getContentSize());
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setCollisionBitmask(Brick_Bitmask);
				 brickBounding->setCategoryBitmask(1);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }
			 //blocks = 0;
			 if (i % 16 == 0) //CURRENTLY MEANS MUST BE 16 BRICKS ON A LINE. 
			 {
				 startLine = startLine - 24;
				 startPos = 80;
			 }

			 if (blocks == 0)
			 {
				 startPos = startPos + (Brick_Size + Brick_Distance);
			 }
		 }
	}
}

void Brick::RemoveBrick(cocos2d::Layer *layer)
{
	
	layer->removeChildByTag(4, true);
}
