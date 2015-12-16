#ifndef __CREDITS_SCENE_H__
#define __CREDITS_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class CreditsScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(CreditsScene);

	void ReturnButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);

	void MenuReturn();

private:
	cocos2d::ui::Button* returnMenu;

};

#endif
