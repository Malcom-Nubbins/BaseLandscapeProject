#pragma once
#include "cocos2d.h"
#include "Brick.h"
#include "Player.h"
#include "Ball.h"
#include "ui/CocosGUI.h"

using namespace std;

class SoundManager
{
public:
	~SoundManager();
	static SoundManager* sharedSoundManager();

	void PreLoadSoundEffect(const char*);
	void PreLoadMusic(const char*);

	void PlaySoundEffect(const char*, bool, float, float, float);
	void PlayMusic(const char*, bool);

	void StopMusic();
	void StopSoundEffect();

	void PauseMusic();
	void ResumeMusic();

private:
	SoundManager();
	static SoundManager* instance;
};

