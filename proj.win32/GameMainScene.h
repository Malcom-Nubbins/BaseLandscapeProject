#ifndef __GAMEMAIN_SCENE_H__
#define __GAMEMAIN_SCENE_H__

#include "cocos2d.h"
#include "Brick.h"
#include "Player.h"
#include "Ball.h"
#include "ui/CocosGUI.h"

class GameScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

	void Update();

	void LeftButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void RightButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void FireButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void PauseButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);

private:
	cocos2d::ui::Button* LeftButton;
	cocos2d::ui::Button* RightButton;
	cocos2d::ui::Button* FireButton;
	cocos2d::ui::Button* PauseButton;
	//cocos2d::Sprite* Paddle;
	//cocos2d::Sprite* Balls;
	//cocos2d::Sprite* Block; //No longer needed?
	cocos2d::PhysicsWorld *GameWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld *scene) { GameWorld = scene; };
	void SetBrick(float i);
	void SetPlayer(float i);
	void SetBall(float i);
	
	Brick brick;
	Player player;
	Ball ball;
};

#endif // __GAMEMAIN_SCENE_H__
