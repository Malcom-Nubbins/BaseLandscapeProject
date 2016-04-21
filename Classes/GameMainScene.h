#ifndef __GAMEMAIN_SCENE_H__
#define __GAMEMAIN_SCENE_H__

#include "cocos2d.h"
#include "Brick.h"
#include "Player.h"
#include "Ball.h"
#include "Death.h"
#include "PowerUp.h"
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

	void update(float dt);

	void LeftButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void RightButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void FireButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void PauseButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void PauseGame();
	void ResumeButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void ReturnButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void RestartButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);

	void Level1ButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void Level2ButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void Level3ButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void Level4ButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void Level5ButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);

	void GameOver();

	void LeftButtonDown();
	void LeftButtonUp();
	void RightButtonDown();
	void RightButtonUp();


protected:
	cocos2d::Array *_bricks;
	cocos2d::Array *_balls;

private:
	cocos2d::ui::Button* LeftButton;
	cocos2d::ui::Button* RightButton;
	cocos2d::ui::Button* FireButton;
	cocos2d::ui::Button* PauseButton;
	cocos2d::ui::Button* ResumeButton;
	cocos2d::ui::Button* ReturnButton;
	cocos2d::ui::Button* RestartButton;
	cocos2d::ui::Button* Level1Select;
	cocos2d::ui::Button* Level2Select;
	cocos2d::ui::Button* Level3Select;
	cocos2d::ui::Button* Level4Select;
	cocos2d::ui::Button* Level5Select;
	cocos2d::ui::Text*	 ScoreLabel;
	cocos2d::ui::Text*	 LivesLabel;
	cocos2d::ui::Text*	 AmmoLabel;
	cocos2d::PhysicsWorld *GameWorld;
	bool isLeftFingerDown;
	bool isRightFingerDown;
	float paddlePos;
	float a;
	float b;
	float x;
	float y;
	float xb;
	float yb;
	int lives;
	int ba;
	int balls;


	cocos2d::PhysicsContact *onContactBegin;

	void SetPhysicsWorld(cocos2d::PhysicsWorld *scene) { GameWorld = scene; };
	void SetBrick(float i);
	void RemoveBrick(float i);
	void SetPlayer(float i);
	void SetBall(float i);
	void SetPowerUp(float i);
	void SetDeath(float i);
	bool setHit(cocos2d::PhysicsContact &contact);
	void Seperate(cocos2d::PhysicsContact &contact);
	bool setHitPaddle(cocos2d::PhysicsContact &contact);
	bool hit;
	int level;
	int number;

	Brick brick;
	Player player;
	Ball ball;
	PowerUp powerUp;
	Death death;
};

#endif // __GAMEMAIN_SCENE_H__
