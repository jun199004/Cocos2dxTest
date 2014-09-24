#include "MainLayer.h"




bool MainLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	_layerout = GUIReader::getInstance()->widgetFromJsonFile("MysticalCard_1/MysticalCard_1.json");
	_layerout->setAnchorPoint(Vec2::ZERO);
	_layerout->setPosition(Vec2::ZERO);
	this->addChild(_layerout);

	//_closeButton = static_cast<ui::Button*>(_layerout->getChildByName("close_Button"));
	//_closeButton->addTouchEventListener(this,toucheventselector(LoginLayer::closeButtonCheck));

	//_loginButton = static_cast<ui::Button*>(_layerout->getChildByName("login_Button"));
	//_loginButton->addTouchEventListener(this, toucheventselector(LoginLayer::loginButtonCheck));

	//_userNameTextField = static_cast<ui::TextField*>(_layerout->getChildByName("name_TextField"));
	//_userNameTextField->setText("test");

	//_passwordTextField01 = static_cast<ui::TextField*>(_layerout->getChildByName("password_TextField"));
	//_passwordTextField01->setText("test");

	//_passwordTextField02 = static_cast<ui::TextField*>(_layerout->getChildByName("confirm_TextField"));
	//_passwordTextField02->setText("test");


	//_loginButtonText = static_cast<ui::TextBMFont*>(_loginButton->getChildByName("login_LabelBMFont"));
	//_loginButtonText->setText("test");
	


	return true;
}



Scene* MainLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = MainLayer::create();
	scene->addChild(layer);
	return scene;
}

void MainLayer::closeButtonCheck(cocos2d::Ref* pSender, cocos2d::ui::TouchEventType type)
{
	Director::getInstance()->end();
}

void MainLayer::loginButtonCheck(cocos2d::Ref* pSender, cocos2d::ui::TouchEventType type)
{

}
