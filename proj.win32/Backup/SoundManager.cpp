#include "SoundManager.h"
#include "SimpleAudioEngine.h"


SoundManager* SoundManager::instance = NULL;


SoundManager* SoundManager::sharedSoundManager()
{
	if (instance == NULL)
	{
		instance = new SoundManager();
	}

	return instance;
}

SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}



void SoundManager::PreLoadMusic(const char* fName)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(fName);
}

void SoundManager::PreLoadSoundEffect(const char* fName)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(fName);
}

void SoundManager::PlaySoundEffect(const char* fName, bool isLooping, float pitch, float pan, float gain)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(fName, isLooping, pitch, pan, gain);
}

void SoundManager::PlayMusic(const char* fName, bool isLooping)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(fName, isLooping);
}

void SoundManager::StopMusic()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}