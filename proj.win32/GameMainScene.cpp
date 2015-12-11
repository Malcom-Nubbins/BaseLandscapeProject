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

	SoundManager::sharedSoundManager()->PreLoadMusic("mainmenu.mp3");
	SoundManager::sharedSoundManager()->PlayMusic("mainmenu.mp3", true);

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
	isLeftFingerDown = false;
	isRightFingerDown = false;


	
	auto contactListner = EventListenerPhysicsContact::create();
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



	//SoundManager::sharedSoundManager()->ResumeMusic();
	return true;
}



bool GameScene::setHit(cocos2d::PhysicsContact &contact)
{
	PhysicsBody *brick = contact.getShapeA()->getBody();
	PhysicsBody *ball = contact.getShapeB()->getBody();
	PhysicsBody *powerup = contact.getShapeB()->getBody();
	PhysicsBody *paddle = contact.getShapeA()->getBody();

	
	if ((1 == brick->getCollisionBitmask() && 2 == ball->getCollisionBitmask()) || (2 == brick->getCollisionBitmask() && 1 == ball->getCollisionBitmask()))// BACK TO FRONT FOR NOW
	{
		CCLOG("Hit");

		//this->removeChild(contact.getShapeB()->getBody()->getNode());
		GameManager::sharedGameManager()->AddToScore(1);

		//Ball::sharedBall()->AddToAcceleration(5000);
		//ScoreLabel->setString(StringUtils::format("%d", GameManager::sharedGameManager()->GetScore()));

		int a = cocos2d::RandomHelper::random_int(2, 4);

		if (a == 4)
		{
			this->schedule(schedule_selector(GameScene::SetPowerUp));
		}
		
	}
	
	else // BACK TO FRONT FOR NOW
	{
		CCLOG("test");
		this->removeChild(contact.getShapeB()->getBody()->getNode());
		GameManager::sharedGameManager()->AddToScore(1);

		int a = cocos2d::RandomHelper::random_int(2, 4);

		if (a == 4)
		{
			this->schedule(schedule_selector(GameScene::SetPowerUp));
		}
	}
	
	if ((1 == powerup->getCollisionBitmask() && 2 == paddle->getCollisionBitmask()) || (2 == powerup->getCollisionBitmask() && 1 == paddle->getCollisionBitmask()))
	{
		CCLOG("Lives UP!");

		GameManager::sharedGameManager()->AddToLives(1);
	}

	//unschedule(schedule_selector(GameScene::SetBrick));
	return true;
	

}

void GameScene::SetBrick(float i)
{
	brick.SetBrick(this);
	unschedule(schedule_selector(GameScene::SetBrick));
}

void GameScene::SetPlayer(float i)
{
	player.SetPlayer(this);
	unschedule(schedule_selector(GameScene::SetPlayer));
}

void GameScene::SetBall(float i)
{
	ball.SetBall(this);
	unschedule(schedule_selector(GameScene::SetBall));

	
}

void GameScene::SetPowerUp(float i)
{
	powerUp.SetPowerUp(this);
	unschedule(schedule_selector(GameScene::SetPowerUp));


}

//void GameScene::SetCollisions(cocos2d::PhysicsContact &contact)
//{
	
//}

void GameScene::LeftButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("Left!");

	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		isLeftFingerDown = true;
		LeftButtonDown();
	}

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
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
		isRightFingerDown = true;
		RightButtonDown();
	}

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
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
		//SoundManager::sharedSoundManager()->StopMusic();

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
		SoundManager::sharedSoundManager()->StopMusic();
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