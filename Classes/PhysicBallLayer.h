#pragma once

#include "cocos2d.h"
USING_NS_CC;



class PhysicBallLayer : public Layer
{
public:
	PhysicBallLayer();
	~PhysicBallLayer();
	CREATE_FUNC(PhysicBallLayer);
	virtual bool init();
	static Scene* createScene();
public:
	void setPhysicWorld(PhysicsWorld* world){ _world = world; };
	bool onContactBegin(const PhysicsContact& contact);
	void onEnter();
private:
	Sprite*			_ball;
	PhysicsWorld*	_world;

	Sprite*			_ballOne;
	Sprite*			_ballTwo;

};