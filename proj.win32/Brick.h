#ifndef __BRICK_H__
#define __BRICK_H__

#include "cocos2d.h"

class Brick //: public cocos2d::Layer
{
public:
	Brick();
	~Brick(); 
	virtual bool init();
	void SetBrick(cocos2d::Layer *layer);
	void RemoveBrick(cocos2d::Layer *layer);
	float startPos = 80;
	float startLine = 600;
	int miss = 0;
	int bricks;
	int blocks;
	int lines;
	int inc;
	int type;
	int level;
protected:
	cocos2d::CCArray *_bricks;

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;
};

#endif //__BRICK_H__