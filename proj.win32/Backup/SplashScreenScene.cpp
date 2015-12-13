#include "SplashScreenScene.h"
#include "HelloWorldScene.h"
#include "Define.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SplashScreenScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SplashScreenScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SplashScreenScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("SplashScreen.csb");

	addChild(rootNode);

	this->scheduleOnce(schedule_selector(SplashScreenScene::TimeMainMenu), Splash_Length);

	//Hard coded size and pos for now. 
	// Could implement an image for the splash screen here.
	// Could implement postion for image here.
	// Add as child (Image)

	return true;
}

void SplashScreenScene::TimeMainMenu(float time)
{
	auto scene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(Transition_Length, scene));
}