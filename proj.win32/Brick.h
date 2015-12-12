#ifndef __BRICK_H__
#define __BRICK_H__

#include "cocos2d.h"

class Brick //: public cocos2d::Layer
{
public:
	static Brick* sharedBrick();

	Brick();
	~Brick(); 
	void SetLevel(int level);

	virtual bool init();
	void SetBrick(cocos2d::Layer *layer);
	void RemoveBrick(cocos2d::Layer *layer);
	float startPos = 140;
	float startLine = 576;
	int miss = 0;
	int bricks;
	int blocks;
	int blocks2;
	int lines;
	int inc;
	int test;
	int type;
	int level;
protected:
	cocos2d::CCArray *_bricks;

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;

	static Brick* instance;
};

#endif //__BRICK_H__