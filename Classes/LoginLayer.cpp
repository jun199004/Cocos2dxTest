#include "LoginLayer.h"
#include "KeyboardNotificationLayer.h"
#include "MainLayer.h"



bool LoginLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	_layerout = GUIReader::getInstance()->widgetFromJsonFile("login/DemoLogin.json");
	this->addChild(_layerout);

	_closeButton = static_cast<ui::Button*>(_layerout->getChildByName("close_Button"));
	_closeButton->addTouchEventListener(this,toucheventselector(LoginLayer::closeButtonCheck));

	_loginButton = static_cast<ui::Button*>(_layerout->getChildByName("login_Button"));
	_loginButton->addTouchEventListener(this, toucheventselector(LoginLayer::loginButtonCheck));

	_userNameTextField = static_cast<ui::TextField*>(_layerout->getChildByName("name_TextField"));
	_userNameTextField->setText("test");

	_passwordTextField01 = static_cast<ui::TextField*>(_layerout->getChildByName("password_TextField"));
	_passwordTextField01->setText("test");

	_passwordTextField02 = static_cast<ui::TextField*>(_layerout->getChildByName("confirm_TextField"));
	_passwordTextField02->setText("test");


	_loginButtonText = static_cast<ui::TextBMFont*>(_loginButton->getChildByName("login_LabelBMFont"));
	_loginButtonText->setText("test");
	
	
	//KeyboardNotificationLayer* keyboradLayer = TextFieldTTFDefaultTest::create();
	//this->addKeyboardNotificationLayer(keyboradLayer);

	return true;
}



Scene* LoginLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = LoginLayer::create();
	scene->addChild(layer);
	return scene;
}

void LoginLayer::closeButtonCheck(cocos2d::Ref* pSender, cocos2d::ui::TouchEventType type)
{
	Director::getInstance()->end();
}

void LoginLayer::loginButtonCheck(cocos2d::Ref* pSender, cocos2d::ui::TouchEventType type)
{
	Director::getInstance()->replaceScene(MainLayer::createScene());
}

void LoginLayer::addKeyboardNotificationLayer(KeyboardNotificationLayer * layer)
{
	_notificationLayer = layer;
	addChild(layer);
}
