#include "GameMainScene.h"
#include "HelloWorldScene.h"
#include "Define.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);// Change to Debugdraw_None to remove red border

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


	Paddle = Sprite::create("Paddle.png");
	this->addChild(Paddle);
	auto paddleBounding = PhysicsBody::createBox(Paddle->getContentSize());

	Ball = Sprite::create("Ball.png");
	auto BallBounding = PhysicsBody::createBox(Ball->getContentSize());
	this->addChild(Ball);

	Paddle->setAnchorPoint(Vec2(0, 0));
	Paddle->setPosition(winSize.width / 2, winSize.height / 6);

	Ball->setAnchorPoint(Vec2(0, 0));
	Ball->setPosition(winSize.width / 2, winSize.height / 5.5);

	auto edgeBody = PhysicsBody::createEdgeBox(winSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
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

	this->schedule(schedule_selector(GameScene::SetBrick), Brick_Debug *winSize.width); // From Flappy bird.

	

	return true;
}

void GameScene::SetBrick(float i)
{
	brick.SetBrick(this);
}

void GameScene::LeftButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{

}


void GameScene::RightButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{

}

void GameScene::FireButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{

}

void GameScene::PauseButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{

}

void GameScene::Update()
{

}