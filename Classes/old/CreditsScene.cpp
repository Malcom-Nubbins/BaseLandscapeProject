#include "CreditsScene.h"
#include "HelloWorldScene.h"
#include "Define.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
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

	returnMenu = static_cast<ui::Button*>(rootNode->getChildByName("menuReturn"));
	returnMenu->addTouchEventListener(CC_CALLBACK_2(CreditsScene::ReturnButtonPressed, this));

	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("credits.mp3", true);

	//auto Background = Sprite::create("REPLACE.png");
	//this->addChild(Background);

	//Background->setAnchorPoint(Vec2(0, 0));
	//Background->setPosition(0, 0);

	return true;
}

void CreditsScene::ReturnButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("Everybody needs credit! &d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(Transition_Length, scene));
		this->MenuReturn();
	}
	this->MenuReturn();
}

void CreditsScene::MenuReturn()
{
	auto winSize = Director::getInstance()->getVisibleSize();

	auto returnMoveTo = MoveTo::create(0.5, Vec2(winSize.width, returnMenu->getPositionY()));
	returnMenu->runAction(returnMoveTo);
}