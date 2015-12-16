#include "GameMainScene.h"
#include "HelloWorldScene.h"
#include "Define.h"
#include "SoundManager.h"
#include "Ball.h"
#include "GameManager.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);// Change to Debugdraw_None to remove red borders , Change to Debugdraw_ALL to add red borders
	//scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

	// 'layer' is an autorelease object
	auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto winSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin(); // Gets the origin on the screen

	auto rootNode = CSLoader::createNode("GameScene.csb");

	addChild(rootNode);


	SoundManager::sharedSoundManager()->PreLoadSoundEffect("ballRebound.mp3");
	SoundManager::sharedSoundManager()->PreLoadSoundEffect("buttonClick.mp3");
	SoundManager::sharedSoundManager()->PreLoadSoundEffect("paddleMove.mp3");
	//auto edgeBody = PhysicsBody::createEdgeBox(winSize = Vec2(1270, 650), PHYSICSBODY_MATERIAL_DEFAULT, 3);

	auto edgeBody = PhysicsBody::createEdgeBox(winSize = Vec2(1270, 650), PhysicsMaterial(0.1f, 1, 0.0f),10);

	PhysicsMaterial(0.0f, 0.0f, 0.0f);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y)); //Can Change the size of the bounding box.
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);


	LeftButton = static_cast<ui::Button*>(rootNode->getChildByName("LeftButton"));
	LeftButton->addTouchEventListener(CC_CALLBACK_2(GameScene::LeftButtonPressed, this));

	RightButton = static_cast<ui::Button*>(rootNode->getChildByName("RightButton"));
	RightButton->addTouchEventListener(CC_CALLBACK_2(GameScene::RightButtonPressed, this));

	FireButton = static_cast<ui::Button*>(rootNode->getChildByName("FireButton"));
	FireButton->addTouchEventListener(CC_CALLBACK_2(GameScene::FireButtonPressed, this));

	PauseButton = static_cast<ui::Button*>(rootNode->getChildByName("PauseButton"));
	PauseButton->addTouchEventListener(CC_CALLBACK_2(GameScene::PauseButtonPressed, this));


	ReturnButton = static_cast<ui::Button*>(rootNode->getChildByName("MenuReturn"));
	ReturnButton->addTouchEventListener(CC_CALLBACK_2(GameScene::ReturnButtonPressed, this));
	ReturnButton->setPositionX(winSize.width + ReturnButton->getContentSize().width);
	ReturnButton->setVisible(false);

	

	
	ba = 1;
	balls =  1;
	CCLOG("tester: %i", balls);
	isLeftFingerDown = false;
	isRightFingerDown = false;


	
	auto contactListner = EventListenerPhysicsContactWithGroup::EventListenerPhysicsContact::create();
	contactListner->onContactBegin = CC_CALLBACK_1(GameScene::setHit, this);
	contactListner->onContactSeparate = CC_CALLBACK_1(GameScene::Seperate,this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListner, this);

	ResumeButton = static_cast<ui::Button*>(rootNode->getChildByName("ResumeButton"));
	ResumeButton->addTouchEventListener(CC_CALLBACK_2(GameScene::ResumeButtonPressed, this));
	ResumeButton->setPositionX(winSize.width + ResumeButton->getContentSize().width);
	ResumeButton->setVisible(false);

	RestartButton = static_cast<ui::Button*>(rootNode->getChildByName("RestartButton"));
	RestartButton->addTouchEventListener(CC_CALLBACK_2(GameScene::RestartButtonPressed, this));
	RestartButton->setPositionX(winSize.width + RestartButton->getContentSize().width);
	RestartButton->setVisible(false);


	if (GameManager::sharedGameManager()->isGameLive == false)
	{
		Level1Select = static_cast<ui::Button*>(rootNode->getChildByName("Level1Select"));
		Level1Select->addTouchEventListener(CC_CALLBACK_2(GameScene::Level1ButtonPressed, this));

		Level2Select = static_cast<ui::Button*>(rootNode->getChildByName("Level2Select"));
		Level2Select->addTouchEventListener(CC_CALLBACK_2(GameScene::Level2ButtonPressed, this));

		Level3Select = static_cast<ui::Button*>(rootNode->getChildByName("Level3Select"));
		Level3Select->addTouchEventListener(CC_CALLBACK_2(GameScene::Level3ButtonPressed, this));

		Level4Select = static_cast<ui::Button*>(rootNode->getChildByName("Level4Select"));
		Level4Select->addTouchEventListener(CC_CALLBACK_2(GameScene::Level4ButtonPressed, this));

		Level5Select = static_cast<ui::Button*>(rootNode->getChildByName("Level5Select"));
		Level5Select->addTouchEventListener(CC_CALLBACK_2(GameScene::Level5ButtonPressed, this));
		//auto Level1MoveTo = MoveTo::create(0.5, Vec2(320, Level1Select->getPositionY()));
		//Level1Select ->runAction(Level1MoveTo);
		//Level1Select->setVisible(false);
	}
	else if (GameManager::sharedGameManager()->isGameLive == true)
	{
		rootNode->removeChildByName("Level1Select");
		rootNode->removeChildByName("Level2Select");
		rootNode->removeChildByName("Level3Select");
		rootNode->removeChildByName("Level4Select");
		rootNode->removeChildByName("Level5Select");
		//this->schedule(schedule_selector(GameScene::SetBrick));
		//Director::getInstance()->getRunningScene()->getPhysicsWorld()->setSpeed(1);
	}

	this->scheduleUpdate();

	ScoreLabel = (ui::Text*)rootNode->getChildByName("Score");
	GameManager::sharedGameManager()->ResetScore();

	LivesLabel = (ui::Text*)rootNode->getChildByName("Lives");
	GameManager::sharedGameManager()->ResetLives();
	//Ball::sharedBall()->ResetAcceleration();

	//SoundManager::sharedSoundManager()->PreLoadMusic("mainmenu.mp3");
	//SoundManager::sharedSoundManager()->PlayMusic("mainmenu.mp3", true);

	//SoundManager::sharedSoundManager()->ResumeMusic();
	return true;
}



bool GameScene::setHit(cocos2d::PhysicsContact &contact)
{

	if (GameManager::sharedGameManager()->isGameLive == true)
	{

		PhysicsBody *a = contact.getShapeA()->getBody();
		PhysicsBody *b = contact.getShapeB()->getBody();

		float* v = new float[2];
		v[0] = a->getVelocity().length(); // Created By An Unknown Source, Via Stack OverFlow
		v[1] = b->getVelocity().length(); // Created By An Unknown Source, Via Stack OverFlow

		contact.setData(v);


		if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))// BACK TO FRONT FOR NOW
		{
			bool hit = true;
			CCLOG(" A Collision has occured");
		}

		else
		{
			bool hit = false;
		}

		if (hit = true)
		{

			if ((a->getCollisionBitmask() == Paddle_Bitmask && b->getCollisionBitmask() == Ball_Bitmask) || (a->getCollisionBitmask() == Ball_Bitmask && b->getCollisionBitmask() == Paddle_Bitmask))
			{
				Ball::sharedBall()->AddToDampening(5000.0f);
				SoundManager::sharedSoundManager()->PlaySoundEffect("ballRebound.mp3", false, 1.0f, 1.0f, 1.0f);
			}

			if ((a->getCollisionBitmask() == Brick_Bitmask && b->getCollisionBitmask() == Ball_Bitmask) || (a->getCollisionBitmask() == Ball_Bitmask && b->getCollisionBitmask() == Brick_Bitmask))
			{
				Ball::sharedBall()->AddToDampening(5000.0f);
				GameManager::sharedGameManager()->AddToScore(1);
				this->removeChild(contact.getShapeB()->getBody()->getNode());

				Ball::sharedBall()->AddToAcceleration(5000);
				//ScoreLabel->setString(StringUtils::format("%d", GameManager::sharedGameManager()->GetScore()));

				Vec2 first = contact.getShapeA()->getBody()->getNode()->convertToWorldSpace(Vec2(50, 50));

				x = first.x;
				y = first.y;

				this->schedule(schedule_selector(GameScene::SetPowerUp));

				//level = 50;
				if (level == 1)
				{
					number = number + 1;
					CCLOG("number = %i", number);

					brick.SetLevel(level);
					//if (number == 5)
					//{
					// CCLOG("level 2");
					// //level = 2;
					// this->removeChild(contact.getShapeA()->getBody()->getNode());
					//this->schedule(schedule_selector(GameScene::SetBrick));
					//this->schedule(schedule_selector(GameScene::SetBall));
					//}
				}

				else if (level == 2)
				{
					number = number + 1;
					brick.SetLevel(level);
					/*if (number == 5)
					{
					level = 3;
					this->removeChild(contact.getShapeA()->getBody()->getNode());
					this->schedule(schedule_selector(GameScene::SetBrick));
					this->schedule(schedule_selector(GameScene::SetBall));
					}*/

				}

				else if (level == 3)
				{
					number = number + 1;
					brick.SetLevel(level);
					/*if (number == 5)
					{
					level = 4;
					this->removeChild(contact.getShapeA()->getBody()->getNode());
					this->schedule(schedule_selector(GameScene::SetBrick));
					this->schedule(schedule_selector(GameScene::SetBall));
					}*/
				}

				else if (level == 4)
				{
					number = number + 1;
					brick.SetLevel(level);
					/*if (number == 5)
					{
					level = 5;
					this->removeChild(contact.getShapeA()->getBody()->getNode());
					this->schedule(schedule_selector(GameScene::SetBrick));
					this->schedule(schedule_selector(GameScene::SetBall));
					}*/
				}
				else if (level == 5)
				{
					number = number + 1;
					brick.SetLevel(level);
				}
			}
			//LIFE
			if ((a->getCollisionBitmask() == Paddle_Bitmask && b->getCollisionBitmask() == LiveUp_Bitmask) || (a->getCollisionBitmask() == LiveUp_Bitmask && b->getCollisionBitmask() == Paddle_Bitmask))
			{
				GameManager::sharedGameManager()->AddToLives(1);

				this->removeChild(contact.getShapeA()->getBody()->getNode());


			}
			//TWO
			if ((a->getCollisionBitmask() == Paddle_Bitmask && b->getCollisionBitmask() == TwoSplit_Bitmask) || (a->getCollisionBitmask() == TwoSplit_Bitmask && b->getCollisionBitmask() == Paddle_Bitmask))
			{

				this->removeChild(contact.getShapeA()->getBody()->getNode());

				Vec2 BallPos = contact.getShapeB()->getBody()->getNode()->convertToWorldSpace(Vec2(50, 50));
				xb = BallPos.x;
				yb = BallPos.y;

				balls = balls + 1;
				ba = ba + 1;
				this->schedule(schedule_selector(GameScene::SetBall));
			}
			//THREE
			if ((a->getCollisionBitmask() == Paddle_Bitmask && b->getCollisionBitmask() == ThreeSplit_Bitmask) || (a->getCollisionBitmask() == ThreeSplit_Bitmask && b->getCollisionBitmask() == Paddle_Bitmask))
			{
				this->removeChild(contact.getShapeA()->getBody()->getNode());

				Vec2 BallPos = contact.getShapeB()->getBody()->getNode()->convertToWorldSpace(Vec2(50, 50));
				xb = BallPos.x;
				yb = BallPos.y;

				balls = balls + 2;
				ba = ba + 2;
				this->schedule(schedule_selector(GameScene::SetBall));

			}
			//FOUR
			if ((a->getCollisionBitmask() == Paddle_Bitmask && b->getCollisionBitmask() == NineSplit_Bitmask) || (a->getCollisionBitmask() == NineSplit_Bitmask && b->getCollisionBitmask() == Paddle_Bitmask))
			{
				this->removeChild(contact.getShapeA()->getBody()->getNode());

				Vec2 BallPos = contact.getShapeB()->getBody()->getNode()->convertToWorldSpace(Vec2(50, 50));
				xb = BallPos.x;
				yb = BallPos.y;

				balls = balls + 8;
				ba = ba + 8;
				this->schedule(schedule_selector(GameScene::SetBall));
			}

			if ((a->getCollisionBitmask() == Death_Bitmask && b->getCollisionBitmask() == Ball_Bitmask) || (a->getCollisionBitmask() == Ball_Bitmask && b->getCollisionBitmask() == Death_Bitmask))
			{
				CCLOG("BALLS B4 amount:%i", balls);
				CCLOG("BA B4 amount:%i", ba);

				this->lives = GameManager::sharedGameManager()->GetLives();
				if (balls <= 1 && lives > 0)
				{
					CCLOG("BALLS amount:%i", balls);
					CCLOG("BA amount:%i", ba);
					GameManager::sharedGameManager()->AddToLives(-1);
					this->schedule(schedule_selector(GameScene::SetBall));
					balls = balls + 1;
					ba = ba + 1;

				}

				else if (balls <= 1 && lives <= 0)
				{
					GameManager::sharedGameManager()->AddToLives(-1);
				}

				if (balls >= 1 && lives > 0)
				{
					CCLOG("BALLS amount:%i", balls);
					CCLOG("BA amount:%i", ba);
					balls = balls - 1;
					ba = ba - 1;
				}

				if (lives <= 0)
				{
					/*auto scene = HelloWorld::createScene();
					Director::getInstance()->replaceScene(TransitionFade::create(Transition_Length, scene));*/

					this->GameOver();
				}
				this->removeChild(contact.getShapeA()->getBody()->getNode());

			}

			if ((a->getCollisionBitmask() == Death_Bitmask && b->getCollisionBitmask() == LiveUp_Bitmask) || (a->getCollisionBitmask() == LiveUp_Bitmask && b->getCollisionBitmask() == Death_Bitmask))
			{
				this->removeChild(contact.getShapeA()->getBody()->getNode());
			}

			if ((a->getCollisionBitmask() == Death_Bitmask && b->getCollisionBitmask() == TwoSplit_Bitmask) || (a->getCollisionBitmask() == TwoSplit_Bitmask && b->getCollisionBitmask() == Death_Bitmask))
			{
				this->removeChild(contact.getShapeA()->getBody()->getNode());

			}

			if ((a->getCollisionBitmask() == Death_Bitmask && b->getCollisionBitmask() == ThreeSplit_Bitmask) || (a->getCollisionBitmask() == ThreeSplit_Bitmask && b->getCollisionBitmask() == Death_Bitmask))
			{
				this->removeChild(contact.getShapeA()->getBody()->getNode());
			}

			if ((a->getCollisionBitmask() == Death_Bitmask && b->getCollisionBitmask() == NineSplit_Bitmask) || (a->getCollisionBitmask() == NineSplit_Bitmask && b->getCollisionBitmask() == Death_Bitmask))
			{
				this->removeChild(contact.getShapeA()->getBody()->getNode());
			}
		}
	}
	return true;
}

void GameScene::Seperate(cocos2d::PhysicsContact &contact) // Created By An Unknown Source, Via Stack OverFlow
{
	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();
	float* v = (float*)contact.getData();

	if (a->getCollisionBitmask() == Ball_Bitmask)
	{

		CCLOG("setVelocity a : %f", a);
		auto va = a->getVelocity();
		va.normalize();
		a->setVelocity(va * v[0]);

		CCLOG("setVelocity a : %f",a);
	}

	if (b->getCollisionBitmask() == Ball_Bitmask)
	{
		CCLOG("setVelocity b : %f", b);
		auto vb = b->getVelocity();
		vb.normalize();
		b->setVelocity(vb * v[1]);
		CCLOG("setVelocity b : %f", b);
	}
	delete v;
}

void GameScene::SetBrick(float i)
{


	CCLOG("level gam: %i", level);

	CCLOG("levelgame after: %i", level);
	brick.SetBrick(this,level);
	unschedule(schedule_selector(GameScene::SetBrick));
	number = 0;
}

void GameScene::SetPlayer(float i)
{
	player.SetPlayer(this);
	unschedule(schedule_selector(GameScene::SetPlayer));
}

void GameScene::SetBall(float i)
{
	CCLOG("ba in setball %f", ba);
	ball.SetBall(this,xb,yb,ba);
	unschedule(schedule_selector(GameScene::SetBall));
	
}

void GameScene::SetPowerUp(float i)
{
	//PowerUp::sharedPowerUp()->SetPowerUpPos(x, y);
	powerUp.SetPowerUp(this,x,y);
	unschedule(schedule_selector(GameScene::SetPowerUp));


}

void GameScene::SetDeath(float i)
{
	death.SetDeath(this);
	unschedule(schedule_selector(GameScene::SetDeath));


}

//void GameScene::SetCollisions(cocos2d::PhysicsContact &contact)
//{
	
//}

void GameScene::Level1ButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	auto winSize = Director::getInstance()->getVisibleSize();
	if (GameManager::sharedGameManager()->isGameLive == false)
	{
		CCLOG("Level 1 Selected.");

		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			
			auto Level1MoveTo = MoveTo::create(0.5, Vec2(winSize.width + Level1Select->getContentSize().width, Level1Select->getPositionY()));
			Level1Select->runAction(Level1MoveTo);
			GameManager::sharedGameManager()->isGameLive = true;
			

			//auto newScene = GameScene::createScene();
			//Director::getInstance()->replaceScene(newScene);
			Level1Select->setVisible(false);
			Level2Select->setVisible(false);
			Level3Select->setVisible(false);
			Level4Select->setVisible(false);
			Level5Select->setVisible(false);
			level = 1;
			brick.SetBrick(this, level);
			this->schedule(schedule_selector(GameScene::SetBall));
			this->schedule(schedule_selector(GameScene::SetPlayer));
			this->schedule(schedule_selector(GameScene::SetDeath));
		}
	}
}

void GameScene::Level2ButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	auto winSize = Director::getInstance()->getVisibleSize();
	if (GameManager::sharedGameManager()->isGameLive == false)
	{
		CCLOG("Level 2 Selected.");

		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			auto Level2MoveTo = MoveTo::create(0.5, Vec2(winSize.width + Level2Select->getContentSize().width, Level2Select->getPositionY()));
			Level2Select->runAction(Level2MoveTo);
			GameManager::sharedGameManager()->isGameLive = true;

			
			//auto newScene = GameScene::createScene();
			//Director::getInstance()->replaceScene(newScene);
			Level1Select->setVisible(false);
			Level2Select->setVisible(false);
			Level3Select->setVisible(false);
			Level4Select->setVisible(false);
			Level5Select->setVisible(false);
			level = 2;
			brick.SetBrick(this, level);
			this->schedule(schedule_selector(GameScene::SetBall));
			this->schedule(schedule_selector(GameScene::SetPlayer));
			this->schedule(schedule_selector(GameScene::SetDeath));
		}
	}
}

void GameScene::Level3ButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	auto winSize = Director::getInstance()->getVisibleSize();
	if (GameManager::sharedGameManager()->isGameLive == false)
	{
		CCLOG("Level 3 Selected.");

		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			auto Level3MoveTo = MoveTo::create(0.5, Vec2(winSize.width + Level3Select->getContentSize().width, Level3Select->getPositionY()));
			Level3Select->runAction(Level3MoveTo);
			GameManager::sharedGameManager()->isGameLive = true;

			
			
			//auto newScene = GameScene::createScene();
			//Director::getInstance()->replaceScene(newScene);
			Level1Select->setVisible(false);
			Level2Select->setVisible(false);
			Level3Select->setVisible(false);
			Level4Select->setVisible(false);
			Level5Select->setVisible(false);
			level = 3;
			brick.SetBrick(this, level);
			this->schedule(schedule_selector(GameScene::SetBall));
			this->schedule(schedule_selector(GameScene::SetPlayer));
			this->schedule(schedule_selector(GameScene::SetDeath));
		}
	}
}

void GameScene::Level4ButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	auto winSize = Director::getInstance()->getVisibleSize();
	if (GameManager::sharedGameManager()->isGameLive == false)
	{
		CCLOG("Level 4 Selected.");

		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			auto Level4MoveTo = MoveTo::create(0.5, Vec2(winSize.width + Level4Select->getContentSize().width, Level4Select->getPositionY()));
			Level4Select->runAction(Level4MoveTo);
			GameManager::sharedGameManager()->isGameLive = true;



			//auto newScene = GameScene::createScene();
			//Director::getInstance()->replaceScene(newScene);
			Level1Select->setVisible(false);
			Level2Select->setVisible(false);
			Level3Select->setVisible(false);
			Level4Select->setVisible(false);
			Level5Select->setVisible(false);
			level = 4;
			brick.SetBrick(this, level);
			this->schedule(schedule_selector(GameScene::SetBall));
			this->schedule(schedule_selector(GameScene::SetPlayer));
			this->schedule(schedule_selector(GameScene::SetDeath));
		}
	}
}

void GameScene::Level5ButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	auto winSize = Director::getInstance()->getVisibleSize();
	if (GameManager::sharedGameManager()->isGameLive == false)
	{
		CCLOG("Level 5 Selected.");

		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			auto Level5MoveTo = MoveTo::create(0.5, Vec2(winSize.width + Level5Select->getContentSize().width, Level5Select->getPositionY()));
			Level5Select->runAction(Level5MoveTo);
			GameManager::sharedGameManager()->isGameLive = true;



			//auto newScene = GameScene::createScene();
			//Director::getInstance()->replaceScene(newScene);
			Level1Select->setVisible(false);
			Level2Select->setVisible(false);
			Level3Select->setVisible(false);
			Level4Select->setVisible(false);
			Level5Select->setVisible(false);
			level = 5;
			brick.SetBrick(this, level);
			this->schedule(schedule_selector(GameScene::SetBall));
			this->schedule(schedule_selector(GameScene::SetPlayer));
			this->schedule(schedule_selector(GameScene::SetDeath));
		}
	}
}

void GameScene::LeftButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{

	if (GameManager::sharedGameManager()->isGameLive == true)
	{
		CCLOG("Left!");

		if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
		{
			//SoundManager::sharedSoundManager()->PlaySoundEffect("paddleMove.mp3", true, 1.0f, 1.0f, 1.0f);
			isLeftFingerDown = true;
			LeftButtonDown();
		}

		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			//SoundManager::sharedSoundManager()->StopSoundEffect();
			LeftButtonUp();
		}
	}
}

void GameScene::LeftButtonDown()
{
	auto winSize = Director::getInstance()->getVisibleSize();
	float paddleSpeed = Paddle_Top_Speed * Paddle_Acceleration;
	paddlePos = player.GetPlayerPosX();
	if (paddlePos > 40)
		player.SetPlayerPos((paddlePos - 6.0f), winSize.height / 6);
	else
		LeftButtonUp();

}

void GameScene::LeftButtonUp()
{
	isLeftFingerDown = false;
}

void GameScene::RightButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{
	if (GameManager::sharedGameManager()->isGameLive == true)
	{
		CCLOG("Right!");
		if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
		{
			//SoundManager::sharedSoundManager()->PlaySoundEffect("paddleMove.mp3", true, 1.0f, 1.0f, 1.0f);
			isRightFingerDown = true;
			RightButtonDown();
		}

		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			//SoundManager::sharedSoundManager()->StopSoundEffect();
			RightButtonUp();
		}
	}
}

void GameScene::RightButtonDown()
{
	
	auto winSize = Director::getInstance()->getVisibleSize();
	float paddleSpeed = Paddle_Top_Speed * Paddle_Acceleration;
	paddlePos = player.GetPlayerPosX();
	if (paddlePos < winSize.width - 40)
		player.SetPlayerPos((paddlePos + 6.0f), winSize.height / 6);
	else
		RightButtonUp();
	
}

void GameScene::RightButtonUp()
{
	isRightFingerDown = false;
}

void GameScene::FireButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("Fire!");
}

void GameScene::PauseButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{
	auto winSize = Director::getInstance()->getVisibleSize();
	CCLOG("Paused!");

	if (GameManager::sharedGameManager()->isGameLive == true)
	{
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			Director::getInstance()->getRunningScene()->getPhysicsWorld()->setSpeed(0);
			//SoundManager::sharedSoundManager()->StopMusic();
			SoundManager::sharedSoundManager()->PlaySoundEffect("buttonClick.mp3", false, 1.0f, 1.0f, 1.0f);

			auto resumeMoveTo = MoveTo::create(0.5, Vec2(winSize.width / 3, ResumeButton->getPositionY()));
			ResumeButton->setVisible(true);
			ResumeButton->runAction(resumeMoveTo);

			auto returnMoveTo = MoveTo::create(0.5, Vec2(winSize.width / 1.5, ReturnButton->getPositionY()));
			ReturnButton->setVisible(true);
			ReturnButton->runAction(returnMoveTo);
		}
	}
}

void GameScene::ResumeButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("Resumed!");
	auto winSize = Director::getInstance()->getVisibleSize();

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		Director::getInstance()->getRunningScene()->getPhysicsWorld()->setSpeed(1);
		SoundManager::sharedSoundManager()->PlaySoundEffect("buttonClick.mp3", false, 1.0f, 1.0f, 1.0f);
		auto resumeMoveTo = MoveTo::create(0.5, Vec2(winSize.width + ResumeButton->getContentSize().width, ResumeButton->getPositionY()));
		ResumeButton->setVisible(true);
		ResumeButton->runAction(resumeMoveTo);

		auto returnMoveTo = MoveTo::create(0.5, Vec2(winSize.width + ReturnButton->getContentSize().width, ReturnButton->getPositionY()));
		ReturnButton->setVisible(true);
		ReturnButton->runAction(returnMoveTo);
	}
}

void GameScene::ReturnButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("Returning to menu!");

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::sharedGameManager()->isGameLive = false;
		SoundManager::sharedSoundManager()->PlaySoundEffect("buttonClick.mp3", false, 1.0f, 1.0f, 1.0f);
		//SoundManager::sharedSoundManager()->StopMusic();
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(Transition_Length, scene));
	}
}


void GameScene::RestartButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("Restarting Game!");
	auto winSize = Director::getInstance()->getVisibleSize();

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		auto newScene = GameScene::createScene();
		Director::getInstance()->replaceScene(newScene);
	;
		GameManager::sharedGameManager()->isGameLive = false;
	}
}

void GameScene::GameOver()
{
	auto winSize = Director::getInstance()->getVisibleSize();
	Director::getInstance()->getRunningScene()->getPhysicsWorld()->setSpeed(0);
	GameManager::sharedGameManager()->isGameLive = false;

	auto returnMoveTo = MoveTo::create(0.5, Vec2(winSize.width / 1.5, ReturnButton->getPositionY()));
	ReturnButton->setVisible(true);
	ReturnButton->runAction(returnMoveTo);

	auto restartMoveTo = MoveTo::create(0.5, Vec2(winSize.width / 3, RestartButton->getPositionY()));
	RestartButton->setVisible(true);
	RestartButton->runAction(restartMoveTo);
}

void GameScene::update(float dt)
{
	if (isLeftFingerDown)
		LeftButtonDown();

	if (isRightFingerDown)
		RightButtonDown();

	ScoreLabel->setString(StringUtils::format("%d", GameManager::sharedGameManager()->GetScore()));
	LivesLabel->setString(StringUtils::format("%d", GameManager::sharedGameManager()->GetLives()));
}