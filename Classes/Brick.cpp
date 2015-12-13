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

	cocos2d::CCArray *_bricks;
	this->_bricks = CCArray::createWithCapacity(L1_Brick_NO);
	this->_bricks->retain();

	
}

void Brick::SetLevel(int level)
{
	this->level += level;
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

	__String *file = __String::createWithFormat("level 5.plist",level); // allows mutiple level .plists
	__Dictionary *list = __Dictionary::createWithContentsOfFile(file->getCString()); //makes a list with all the data
	__String *Bricks = __String::create(list->valueForKey("Bricks")->getCString()); //assiging a key.
	__String *Lines = __String::create(list->valueForKey("Lines")->getCString());

	 bricks = Bricks->intValue();
	 lines = Lines->intValue();

	 //CCLOG("Bricks: %i", bricks);
	 //CCLOG("Lines: %i", lines);

	 for (int i = 1; i < bricks; i++)
	 {
		// blocks = i;

		 if (i == 1)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("1")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("1b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 2)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("2")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("2b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 3)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("3")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("3b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 4)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("4")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("4b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 5)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("5")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("5b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 6)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("6")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("6b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 7)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("7")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("7b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 8)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("8")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("8b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 9)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("9")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("9b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 10)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("10")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("10b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 11)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("11")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("11b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 12)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("12")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("12b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 13)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("13")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("13b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 14)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("14")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("14b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 15)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("15")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("15b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 16)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("16")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("16b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 17)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("17")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("17b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 18)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("18")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("18b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 19)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("19")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("19b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 20)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("20")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("20b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 21)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("21")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("21b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 22)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("22")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("22b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 23)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("23")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("23b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 24)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("24")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("24b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 25)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("25")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("25b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 26)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("26")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("26b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 27)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("27")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("27b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 28)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("28")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("28b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 29)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("29")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("29b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 30)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("31")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("31b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 32)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("32")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("32b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 33)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("34")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("34b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 35)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("35")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("35b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 36)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("36")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("36b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 37)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("37")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("37b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 38)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("38")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("38b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 39)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("39")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("39b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 40)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("40")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("40b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 41)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("41")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("41b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 42)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("42")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("42b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 43)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("43")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("43b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 44)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("44")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("44b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 45)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("45")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("45b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 46)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("46")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("46b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 47)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("47")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("47b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 48)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("48")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("48b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 49)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("49")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("49b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 50)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("50")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("50b")->getCString());
			 type = Type->intValue();
		 }


		 else if (i == 51)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("51")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("51b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 52)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("52")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("52b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 53)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("53")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("53b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 54)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("54")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("54b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 55)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("55")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("55b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 56)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("56")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("56b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 57)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("57")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("57b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 58)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("58")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("58b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 59)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("59")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("59b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 60)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("60")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("60b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 61)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("61")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("61b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 62)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("62")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("62b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 63)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("63")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("63b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 64)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("64")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("64b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 65)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("65")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("65b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 66)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("66")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("66b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 67)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("67")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("67b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 68)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("68")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("68b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 69)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("69")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("69b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 70)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("70")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("70b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 71)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("71")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("71b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 72)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("72")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("72b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 73)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("73")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("73b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 74)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("74")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("74b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 75)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("75")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("75b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 76)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("76")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("76b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 77)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("77")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("77b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 78)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("78")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("78b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 79)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("79")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("79b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 80)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("80")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("80b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 81)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("81")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("81b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 82)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("82")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("82b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 83)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("83")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("83b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 84)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("84")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("84b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 85)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("85")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("85b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 86)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("86")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("86b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 87)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("87")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("87b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 88)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("88")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("88b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 89)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("89")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("89b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 90)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("90")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("90b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 91)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("91")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("91b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 92)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("92")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("92b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 93)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("93")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("93b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 94)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("94")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("94b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 95)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("95")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("95b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 96)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("96")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("96b")->getCString());
			 type = Type->intValue();
		 } 

		 else if (i == 97)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("97")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("97b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 98)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("98")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("98b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 99)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("100")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("100b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 101)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("101")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("101b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 102)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("102")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("102b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 103)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("103")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("103b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 104)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("104")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("104b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 105)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("105")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("105b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 106)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("107")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("108b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 108)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("108")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("108b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 109)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("109")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("109b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 12)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("12")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("12b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 110)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("110")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("110b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 111)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("111")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("111b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 112)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("112")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("112b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 113)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("113")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("113b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 114)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("114")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("114b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 116)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("116")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("116b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 117)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("117")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("117b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 118)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("118")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("118b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 119)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("119")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("119b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 120)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("120")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("120b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 121)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("121")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("121b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 122)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("122")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("122b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 123)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("123")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("123b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 124)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("124")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("124b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 125)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("125")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("125b")->getCString());
			 type = Type->intValue();
		 }
			 if (i == 126)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("126")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("126b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 128)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("128")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("128b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 129)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("129")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("129b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 130)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("130")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("130b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 131)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("131")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("131b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 132)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("132")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("132b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 133)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("133")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("133b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 134)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("134")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("134b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 135)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("135")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("135b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 136)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("136")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("136b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 137)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("137")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("137b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 138)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("138")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("138b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 139)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("139")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("139b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 140)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("140")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("140b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 141)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("141")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("141b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 142)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("142")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("142b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 143)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("143")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("143b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 144)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("144")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("144b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 145)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("145")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("145b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 146)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("146")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("146b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 147)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("147")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("147b")->getCString());
			 type = Type->intValue();
		 }


		 else if (i == 148)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("148")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("148b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 149)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("149")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("149b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 150)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("150")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("150b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 151)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("151")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("151b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 152)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("152")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("152b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 153)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("153")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("153b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 154)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("154")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("154b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 155)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("155")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("155b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 156)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("156")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("156b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 157)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("157")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("157b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 158)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("158")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("158b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 159)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("159")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("159b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 160)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("160")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("160b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 161)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("161")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("161b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 162)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("162")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("162b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 163)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("163")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("163b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 164)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("164")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("164b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 165)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("165")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("165b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 166)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("166")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("166b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 167)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("167")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("167b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 168)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("168")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("168b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 169)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("169")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("169b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 170)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("170")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("170b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 171)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("171")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("171b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 172)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("172")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("172b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 173)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("173")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("173b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 174)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("174")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("174b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 175)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("175")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("175b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 176)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("176")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("176b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 177)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("178")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("178b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 179)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("179")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("179b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 180)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("180")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("180b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 181)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("181")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("181b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 182)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("182")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("182b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 183)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("183")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("183b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 184)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("184")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("184b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 185)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("185")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("185b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 186)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("186")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("186b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 187)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("187")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("187b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 188)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("188")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("188b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 189)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("189")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("189b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 190)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("190")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("190b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 191)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("191")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("191b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 192)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("192")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("192b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 193)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("193")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("193b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 194)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("194")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("194b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 195)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("195")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("195b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 196)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("196")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("196b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 197)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("197")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("197b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 198)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("198")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("198b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 199)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("199")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("199b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 200)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("200")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("200b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 201)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("201")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("201b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 202)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("202")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("202b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 203)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("203")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("203b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 204)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("204")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("204b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 205)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("205")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("205b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 206)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("206")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("206b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 207)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("207")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("207b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 208)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("208")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("208b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 209)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("209")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("209b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 210)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("210")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("210b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 211)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("211")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("211b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 212)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("212")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("212b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 213)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("213")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("213b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 214)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("214")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("214b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 215)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("215")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("215b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 216)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("216")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("216b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 217)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("217")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("217b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 218)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("218")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("218b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 219)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("219")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("219b")->getCString());
			 type = Type->intValue();
		 }

		 else if (i == 220)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("220")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("220b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 221)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("221")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("221b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 222)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("222")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("222b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 223)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("223")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("223b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 224)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("224")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("224b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 225)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("225")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("225b")->getCString());
			 type = Type->intValue();
		 }
		 else if (i == 226)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("226")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("226b")->getCString());
			 type = Type->intValue();
		 }
		 if (blocks == 0 || blocks == 1)
		 {
			 if (type == 1)
			 {
				 CCLOG("Violet Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 CCSprite *basicbrick = CCSprite::create("Violet Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Yellow Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Orange Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Cyan Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Green Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Blue Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Purple Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Red Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("White Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Grey Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Black Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Amber Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Dakota Brick.png");
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
				 CCSprite *basicbrick = CCSprite::create("Blue Grey Brick.png");
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
