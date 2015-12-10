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
	//blocks = 0;
	lines = 0;
	inc = 1;
	type = 1;
	level = 4; // Level 2 gives different block layout //so does level 3 YEAHHHHHH!!!!!! I May be drunk while typing this.
	__String spawn = "1";

	__String *file = __String::createWithFormat("level %i.plist",level); // allows mutiple level .plists
	__Dictionary *list = __Dictionary::createWithContentsOfFile(file->getCString()); //makes a list with all the data
	__String *Bricks = __String::create(list->valueForKey("Bricks")->getCString()); //assiging a key.
	__String *Lines = __String::create(list->valueForKey("Lines")->getCString());

	 bricks = Bricks->intValue();
	 lines = Lines->intValue();

	 CCLOG("level: %i", level);
	 CCLOG("Bricks: %i", bricks);
	 CCLOG("Lines: %i", lines);

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

		 if (i == 2)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("2")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("2b")->getCString());
			 type = Type->intValue();
		 }

		 if (i == 3)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("3")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("3b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 4)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("4")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("4b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 5)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("5")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("5b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 6)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("6")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("6b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 7)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("7")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("7b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 8)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("8")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("8b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 9)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("9")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("9b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 10)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("10")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("10b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 11)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("11")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("11b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 12)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("12")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("12b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 13)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("13")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("13b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 14)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("14")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("14b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 15)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("15")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("15b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 16)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("16")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("16b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 17)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("17")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("17b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 18)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("18")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("18b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 19)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("19")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("19b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 20)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("20")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("20b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 21)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("21")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("21b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 22)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("22")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("22b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 23)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("23")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("23b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 24)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("24")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("24b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 25)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("25")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("25b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 26)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("26")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("26b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 27)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("27")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("27b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 28)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("28")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("28b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 29)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("29")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("29b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 30)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("31")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("31b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 32)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("32")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("32b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 33)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("34")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("34b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 35)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("35")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("35b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 36)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("36")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("36b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 37)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("37")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("37b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 38)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("38")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("38b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 39)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("39")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("39b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 40)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("40")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("40b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 41)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("41")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("41b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 42)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("42")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("42b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 43)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("43")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("43b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 44)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("44")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("44b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 45)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("45")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("45b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 46)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("46")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("46b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 47)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("47")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("47b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 48)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("48")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("48b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 49)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("49")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("49b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 50)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("50")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("51b")->getCString());
			 type = Type->intValue();
		 }


		 if (i == 51)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("51")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("51b")->getCString());
			 type = Type->intValue();
		 }

		 if (i == 52)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("52")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("52b")->getCString());
			 type = Type->intValue();
		 }

		 if (i == 53)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("53")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("53b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 54)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("54")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("54b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 55)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("55")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("55b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 56)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("56")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("56b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 57)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("57")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("57b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 58)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("58")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("58b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 59)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("59")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("59b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 60)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("60")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("60b")->getCString());
			 type = Type->intValue();
		 }

		 if (i == 61)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("61")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("61b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 62)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("62")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("62b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 63)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("63")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("63b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 64)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("64")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("64b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 65)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("65")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("65b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 66)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("66")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("66b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 67)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("67")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("67b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 68)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("68")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("68b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 69)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("69")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("69b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 70)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("70")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("70b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 71)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("71")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("71b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 72)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("72")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("72b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 73)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("73")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("73b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 74)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("74")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("74b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 75)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("75")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("75b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 76)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("76")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("76b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 77)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("77")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("77b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 78)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("78")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("78b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 79)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("79")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("79b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 80)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("80")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("80b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 81)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("81")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("81b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 82)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("82")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("82b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 83)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("83")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("83b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 84)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("84")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("84b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 85)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("85")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("85b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 86)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("86")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("86b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 87)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("87")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("87b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 88)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("88")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("88b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 89)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("89")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("89b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 90)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("90")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("90b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 91)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("91")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("91b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 92)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("92")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("92b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 93)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("93")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("93b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 94)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("94")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("94b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 95)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("95")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("95b")->getCString());
			 type = Type->intValue();
		 }
		 if (i == 96)
		 {
			 __String *Block = __String::createWithFormat(list->valueForKey("96")->getCString());
			 blocks = Block->intValue();
			 __String *Type = __String::createWithFormat(list->valueForKey("96b")->getCString());
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
				 brickBounding->setCollisionBitmask(1);
				 brickBounding->setContactTestBitmask(true);
				 brickBounding->setDynamic(false);
				 brickBounding->setGravityEnable(true);
				 basicbrick->setPhysicsBody(brickBounding); //sets a bounding box around brick.
				 startPos = startPos + (Brick_Size + Brick_Distance);
				 basicbrick->setPosition(Vec2(startPos, startLine));;
				 layer->addChild(basicbrick, 1);
			 }

			 if (type == 2)
			 {
				 CCLOG("Yellow Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 CCSprite *basicbrick = CCSprite::create("Yellow Brick.png");
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
			 }

			 if (type == 3)
			 {
				 CCLOG(" Orange Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 CCSprite *basicbrick = CCSprite::create("Orange Brick.png");
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
			 }

			 if (type == 4)
			 {
				 CCLOG("Cyan Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 CCSprite *basicbrick = CCSprite::create("Cyan Brick.png");
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
			 }

			 if (type == 5)
			 {
				 CCLOG("Green Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 CCSprite *basicbrick = CCSprite::create("Green Brick.png");
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
			 }

			 if (type == 6)
			 {
				 CCLOG("Blue Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 CCSprite *basicbrick = CCSprite::create("Blue Brick.png");
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
			 }

			 if (type == 7)
			 {
				 CCLOG("Purple Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 CCSprite *basicbrick = CCSprite::create("Purple Brick.png");
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
			 }

			 if (type == 8)
			 {
				 CCLOG("Red Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 CCSprite *basicbrick = CCSprite::create("Red Brick.png");
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
			 }

			 if (type == 9)
			 {
				 CCLOG("White Brick"); //COCOS BUG: WONT ALWAYS SHOW IN OUTPUT
				 CCSprite *basicbrick = CCSprite::create("White Brick.png");
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
