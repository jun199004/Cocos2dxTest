#pragma once

/************************************************************************/
/* Á£×ÓÏµÍ³                                                                     */
/************************************************************************/
#include "cocos2d.h"
USING_NS_CC;
typedef enum   ¢Ù
{
	kNull = 0,
	kExplosion = 1
	, kFire
	, kFireworks
	, kFlower
	, kGalaxy
	, kMeteor
	, kRain
	, kSmoke
	, kSnow
	, kSpiral
	, kSun
} ActionTypes;

class ParticleTestLayer :public Layer
{
public:
	CREATE_FUNC(ParticleTestLayer);
	virtual bool init();
	static Scene* createScene();

public:
	void funEventTouch(Sprite* sprite);
	bool onTouchBeganss(Touch* touch, Event* ev);
	void onTouchMovess(Touch* touch, Event* ev);
	void onTouchEndss(Touch* touch, Event* ev);

private:
	MotionStreak*		_streak;
};