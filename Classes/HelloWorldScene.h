#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Credits;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void Update(float);

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

	void StartButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void CreditsButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);

	void StartGame();
	void EndGame();

private:
	cocos2d::Sprite* Paddle;
	cocos2d::Sprite* Ball;
	cocos2d::Sprite* Block;
	cocos2d::Label* scoreLabel;
	cocos2d::Label* ammoCount;
	cocos2d::Label* livesCount;
	cocos2d::Label* currentPower;
};

#endif // __HELLOWORLD_SCENE_H__
