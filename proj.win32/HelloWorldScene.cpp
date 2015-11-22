#include "HelloWorldScene.h"
#include "GameMainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Define.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
	auto creditsNode = CSLoader::createNode("Credits.csb");
	addChild(creditsNode);

	this->scheduleUpdate();

	auto winSize = Director::getInstance()->getVisibleSize();

	// Initialise the starting scene (main menu)
	scene = 1;

	//Initialise buttons, sprites, labels/text
	// To add: Start button, Player sprites, labels

	Start = static_cast<ui::Button*>(rootNode->getChildByName("Start"));
	Start->addTouchEventListener(CC_CALLBACK_2(HelloWorld::StartButtonPressed, this));

	Credits = static_cast<ui::Button*>(rootNode->getChildByName("Credits"));
	Credits->addTouchEventListener(CC_CALLBACK_2(HelloWorld::CreditsButtonPressed, this));
	

    return true;
}

void HelloWorld::Update(float delta)
{
	auto winSize = Director::getInstance()->getVisibleSize();

	if (scene == 1) // Main Menu
	{

	}
	else if (scene == 2) // Game Scene
	{

	}
	else if (scene == 3) //Game Over
	{

	}
	else if (scene == 4) // Credits
	{

	}
}

void HelloWorld::StartButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type) 
{
	CCLOG("Push me, and then just touch me! &d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		auto scene = GameScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(Transition_Length, scene));
		//this->CreditsScene();
	}
	//this->CreditsScene();
}


void HelloWorld::CreditsButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("Push me, and then just touch me! &d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		this->CreditsScene();
	}
	this->CreditsScene();
}

void HelloWorld::MainMenu()
{
	scene = 1;
}

void HelloWorld::StartGame()
{
	scene = 2;
}

void HelloWorld::EndGame()
{
	scene = 3;
}

void HelloWorld::CreditsScene()
{
	auto winSize = Director::getInstance()->getVisibleSize();
	scene = 4;

	/*auto startMoveTo = MoveTo::create(0.5, Vec2(winSize.width, Start->getPositionY()));
	Start->runAction(startMoveTo);*/

	auto creditsMoveTo = MoveTo::create(0.5, Vec2(winSize.width, Credits->getPositionY()));
	Credits->runAction(creditsMoveTo);

}