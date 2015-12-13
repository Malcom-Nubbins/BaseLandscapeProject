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

	auto edgeBody = PhysicsBody::createEdgeBox(winSize = Vec2(1270, 650), PHYSICSBODY_MATERIAL_DEFAULT, 3);
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

	this->schedule(schedule_selector(GameScene::SetBrick)); 
	this->schedule(schedule_selector(GameScene::SetPlayer)); 
	this->schedule(schedule_selector(GameScene::SetBall));
	ba = 1;
	balls = 1;
	CCLOG("tester: %i", balls);
	this->schedule(schedule_selector(GameScene::SetDeath));
	isLeftFingerDown = false;
	isRightFingerDown = false;


	
	auto contactListner = EventListenerPhysicsContactWithGroup::EventListenerPhysicsContact::create();
	contactListner->onContactBegin = CC_CALLBACK_1(GameScene::setHit, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListner, this);

	ResumeButton = static_cast<ui::Button*>(rootNode->getChildByName("ResumeButton"));
	ResumeButton->addTouchEventListener(CC_CALLBACK_2(GameScene::ResumeButtonPressed, this));
	ResumeButton->setPositionX(winSize.width + ResumeButton->getContentSize().width);
	ResumeButton->setVisible(false);

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
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();
	
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
		}

		if ((a->getCollisionBitmask() == Brick_Bitmask && b->getCollisionBitmask() == Ball_Bitmask) || (a->getCollisionBitmask() == Ball_Bitmask && b->getCollisionBitmask() == Brick_Bitmask))
		{
			Ball::sharedBall()->AddToDampening(5000.0f);
			GameManager::sharedGameManager()->AddToScore(1);
			this->removeChild(contact.getShapeB()->getBody()->getNode());
			
			Ball::sharedBall()->AddToAcceleration(5000);
			//ScoreLabel->setString(StringUtils::format("%d", GameManager::sharedGameManager()->GetScore()));

				Vec2 first = contact.getShapeA()->getBody()->getNode()->convertToWorldSpace(Vec2(50, 50));
				
				//CCLOG("X: %f",x);
				//CCLOG("Y: %f", y);
				//CCLOG("position = (%f,%f)", x, y);
				x = first.x;
				y = first.y;

				
				CCLOG("position = (%f,%f)", first.x, first.y);
				this->schedule(schedule_selector(GameScene::SetPowerUp));

				level = 50;
			 if (level == 1)
			{
				 number = number + 1;
				 CCLOG("number = %i", number);
				 if (number == 5)
				 {
					 CCLOG("level 2");
					 level = 2;
					 this->removeChild(contact.getShapeA()->getBody()->getNode());
					this->schedule(schedule_selector(GameScene::SetBrick));
					this->schedule(schedule_selector(GameScene::SetBall));
				 }
			}

			else if (level == 2)
			{
				number = number + 1;

				if (number == 5)
				{
					level = 3;
					this->removeChild(contact.getShapeA()->getBody()->getNode());
					this->schedule(schedule_selector(GameScene::SetBrick));
					this->schedule(schedule_selector(GameScene::SetBall));
				}

			}

			else if (level == 3)
			{
				number = number + 1;

				if (number == 5)
				{
					level = 4;
					this->removeChild(contact.getShapeA()->getBody()->getNode());
					this->schedule(schedule_selector(GameScene::SetBrick));
					this->schedule(schedule_selector(GameScene::SetBall));
				}
			}

			else if (level == 4)
			{
				number = number + 1;

				if (number == 5)
				{
					level = 5;
					this->removeChild(contact.getShapeA()->getBody()->getNode());
					this->schedule(schedule_selector(GameScene::SetBrick));
					this->schedule(schedule_selector(GameScene::SetBall));
				}
			}
		}
		//LIFE
		if ((a->getCollisionBitmask() == Paddle_Bitmask && b->getCollisionBitmask() == LiveUp_Bitmask) || (a->getCollisionBitmask() == LiveUp_Bitmask && b->getCollisionBitmask() == Paddle_Bitmask))
		{
			GameManager::sharedGameManager()->AddToLives(1);
			ba = 1;
			
			CCLOG("BALLS test:%i", balls);
			this->removeChild(contact.getShapeA()->getBody()->getNode());
		}
		//TWO
		if ((a->getCollisionBitmask() == Paddle_Bitmask && b->getCollisionBitmask() == TwoSplit_Bitmask) || (a->getCollisionBitmask() == TwoSplit_Bitmask && b->getCollisionBitmask() == Paddle_Bitmask))
		{

			this->removeChild(contact.getShapeA()->getBody()->getNode());

			xb = 700;
			yb = 300;
			ba = 1;
			balls = balls + 1;
			CCLOG("BALLS 2:%i", balls);
			this->schedule(schedule_selector(GameScene::SetBall));
		}
		//THREE
		if ((a->getCollisionBitmask() == Paddle_Bitmask && b->getCollisionBitmask() == ThreeSplit_Bitmask) || (a->getCollisionBitmask() == ThreeSplit_Bitmask && b->getCollisionBitmask() == Paddle_Bitmask))
		{
			this->removeChild(contact.getShapeA()->getBody()->getNode());
			ba = 2;
			balls = balls + 2;
			this->schedule(schedule_selector(GameScene::SetBall));
			
		}
		//FOUR
		if ((a->getCollisionBitmask() == Paddle_Bitmask && b->getCollisionBitmask() == NineSplit_Bitmask) || (a->getCollisionBitmask() == NineSplit_Bitmask && b->getCollisionBitmask() == Paddle_Bitmask))
		{
			this->removeChild(contact.getShapeA()->getBody()->getNode());
			ba = 8;
			balls = balls + 8;
			this->schedule(schedule_selector(GameScene::SetBall));
		}

		if ((a->getCollisionBitmask() == Death_Bitmask && b->getCollisionBitmask() == Ball_Bitmask) || (a->getCollisionBitmask() == Ball_Bitmask && b->getCollisionBitmask() == Death_Bitmask))
		{

			if (balls <= 1)
			{
				CCLOG("BALLS:%i", balls);
				GameManager::sharedGameManager()->AddToLives(-1);
				this->schedule(schedule_selector(GameScene::SetBall));
			}
			balls = balls - 1;
			CCLOG("BALLS Death:%i", balls);
			this->lives = GameManager::sharedGameManager()->GetLives();
			if (lives == 0)
			{
				auto scene = HelloWorld::createScene();
				Director::getInstance()->replaceScene(TransitionFade::create(Transition_Length, scene));
			}
			this->removeChild(contact.getShapeA()->getBody()->getNode());
			ba = 1;
			
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
	return true;
}

void GameScene::SetBrick(float i)
{


	CCLOG("level gam: %i", level);
	if (level <= 0)
	{
		level = 1;
	}
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
	ball.SetBall(this,xb,yb,ba);
	unschedule(schedule_selector(GameScene::SetBall));
	ba = 0;
	
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

void GameScene::LeftButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("Left!");

	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		SoundManager::sharedSoundManager()->PlaySoundEffect("paddleMove.mp3", true, 1.0f, 1.0f, 1.0f);
		isLeftFingerDown = true;
		LeftButtonDown();
	}

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		SoundManager::sharedSoundManager()->StopSoundEffect();
		LeftButtonUp();
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
	CCLOG("Right!");
	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		SoundManager::sharedSoundManager()->PlaySoundEffect("paddleMove.mp3", true, 1.0f, 1.0f, 1.0f);
		isRightFingerDown = true;
		RightButtonDown();
	}

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		SoundManager::sharedSoundManager()->StopSoundEffect();
		RightButtonUp();
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

	// Temporary menu return. Takes the user back to menu, and resets the game scene. *ONLY FOR TESTING. WILL BE REMOVED LATER FOR PROPER PAUSE MENU*

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
		SoundManager::sharedSoundManager()->PlaySoundEffect("buttonClick.mp3", false, 1.0f, 1.0f, 1.0f);
		//SoundManager::sharedSoundManager()->StopMusic();
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(Transition_Length, scene));
	}
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