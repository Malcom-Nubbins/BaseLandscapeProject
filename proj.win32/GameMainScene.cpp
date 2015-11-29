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
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

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

	auto Background = Sprite::create("REPLACE.png");
	this->addChild(Background);

	Paddle = Sprite::create("Paddle.png");
	this->addChild(Paddle);

	Ball = Sprite::create("Ball.png");
	this->addChild(Ball);

	Block = Sprite::create("White Brick.png");
	this->addChild(Block);

	Background->setAnchorPoint(Vec2(0, 0));
	Background->setPosition(0, 0);

	Paddle->setAnchorPoint(Vec2(0, 0));
	Paddle->setPosition(winSize.width / 2, winSize.height / 6);

	Ball->setAnchorPoint(Vec2(0, 0));
	Ball->setPosition(winSize.width / 2, winSize.height / 5.5);

	auto edgeBody = PhysicsBody::createEdgeBox(winSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);

	return true;
}
