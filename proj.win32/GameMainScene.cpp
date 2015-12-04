#include "GameMainScene.h"
#include "HelloWorldScene.h"
#include "Define.h"
#include "SoundManager.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);// Change to Debugdraw_None to remove red borders , Change to Debugdraw_ALL to add red borders

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

	auto edgeBody = PhysicsBody::createEdgeBox(winSize, PHYSICSBODY_MATERIAL_DEFAULT, 3); 
	PhysicsMaterial(0.1f, 1.0f, 0.0f);
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

	this->schedule(schedule_selector(GameScene::SetBrick)); 
	this->schedule(schedule_selector(GameScene::SetPlayer)); 
	this->schedule(schedule_selector(GameScene::SetBall));
	
	isLeftFingerDown = false;
	isRightFingerDown = false;

	SoundManager::sharedSoundManager()->PreLoadMusic("mainmenu.mp3");
	SoundManager::sharedSoundManager()->PlayMusic("mainmenu.mp3", true);

	this->scheduleUpdate();
	

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
	CCLOG("Paused!");

	// Temporary menu return. Takes the user back to menu, and resets the game scene. *ONLY FOR TESTING. WILL BE REMOVED LATER FOR PROPER PAUSE MENU*

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
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
}