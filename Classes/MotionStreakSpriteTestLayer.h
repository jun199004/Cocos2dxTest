#pragma once

#include "cocos2d.h"
USING_NS_CC;

/************************************************************************/
/*��βЧ��ʵ��
�ο���ַ http://blog.csdn.net/song_hui_xiang/article/details/27548049                                                                     */
/************************************************************************/
class MotionStreakSpriteTestLayer :public Layer
{
public:
	CREATE_FUNC(MotionStreakSpriteTestLayer);
	virtual bool init();
	static Scene* createScene();

	bool onTouchBeganss(Touch* touch, Event* ev);
	void onTouchMovess(Touch* touch, Event* ev);
	void onTouchEndss(Touch* touch, Event* ev);
private:
	MotionStreak*		_streak;
};