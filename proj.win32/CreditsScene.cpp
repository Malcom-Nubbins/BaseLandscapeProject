#include "CreditsScene.h"
#include "HelloWorldScene.h"
#include "Define.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

using namespace cocostudio::timeline;


Scene* CreditsScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CreditsScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool CreditsScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("Credits.csb");

	addChild(rootNode);

	//auto Background = Sprite::create("REPLACE.png");
	//this->addChild(Background);

	//Background->setAnchorPoint(Vec2(0, 0));
	//Background->setPosition(0, 0);

	return true;
}