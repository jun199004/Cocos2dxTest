#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;
USING_NS_CC;

//
//#include "cocos2d.h"
//#include "cocos-ext.h"
//#include "CocosGUI.h"
//#include "cocostudio/CocoStudio.h"
//USING_NS_CC_EXT;
//using namespace cocostudio;
//USING_NS_CC;



class KeyboardNotificationLayer;
class LoginLayer :public Layer
{
public:
	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(LoginLayer);
public:
	void closeButtonCheck(cocos2d::Ref* pSender, cocos2d::ui::TouchEventType type);
	void loginButtonCheck(cocos2d::Ref* pSender, cocos2d::ui::TouchEventType type);
	void addKeyboardNotificationLayer(KeyboardNotificationLayer * layer);

private:

	ui::Widget*				_layerout;
	ui::Button*				_closeButton;
	ui::Button*				_loginButton;
	ui::TextBMFont*			_loginButtonText;
	ui::TextField*			_userNameTextField;
	ui::TextField*			_passwordTextField01;
	ui::TextField*			_passwordTextField02;
private:
	KeyboardNotificationLayer * _notificationLayer;
};