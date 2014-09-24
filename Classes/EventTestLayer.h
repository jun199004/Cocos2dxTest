#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

/************************************************************************/
/* 用户交互事件                                                                     */
/************************************************************************/
#include "cocos2d.h"
USING_NS_CC;

class EventTestLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(EventTestLayer);

	cocos2d::Label		*m_label;

	void funEventTouch(Sprite* sprite,int nidx=0);
	bool onTouchBeganss(Touch* touch, Event* ev);
	void onTouchMovess(Touch* touch, Event* ev);
	void onTouchEndss(Touch* touch, Event* ev);
	void onTouchCancless(Touch* touch, Event* ev);

	void keyboardEventTouch();
	void onKeyPressedss(EventKeyboard::KeyCode keycode, Event* ev);
	void onKeyReleasedss(EventKeyboard::KeyCode keycode, Event* ev);

	void funEventMouse(Sprite* sprite);
	void onMouseDownss(Event* ev);
	void onMouseMovess(Event* ev);
	void onMouseUpss(Event* ev);
	void onMouseScrollss(Event* ev);

	void funEventCustom();
	void dispatcherCustomEvents(float at);
	void onEventCustom(EventCustom* event);


	void funEventAcceleration();
	void onAcceleration(Acceleration* acc, Event* event);

};

#endif // __HELLOWORLD_SCENE_H__
