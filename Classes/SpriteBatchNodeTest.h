#pragma once


#include "cocos2d.h"
USING_NS_CC;


class SpriteBatchNodeLayer :public Layer
{
public:
	CREATE_FUNC(SpriteBatchNodeLayer);
	virtual bool init();
	static Scene* createScene();
};


class MyNode :public Node
{
public:
	CREATE_FUNC(MyNode);
	virtual bool init();
private:
};