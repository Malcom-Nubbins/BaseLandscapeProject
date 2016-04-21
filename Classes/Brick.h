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
	void SetBrick(cocos2d::Layer *layer,int level);
	void RemoveBrick(cocos2d::Layer *layer);
	int startPos;
	int startLine;
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
	cocos2d::Array *_bricks;

private:
	cocos2d::Size WinSize;
	cocos2d::Vec2 origin;

	static Brick* instance;
};

#endif //__BRICK_H__