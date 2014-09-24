#include "MotionStreakSpriteTestLayer.h"


bool MotionStreakSpriteTestLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto node = Sprite::create("CloseNormal.png");
	node->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0));
	this->addChild(node);
	//////////////////////////////////////////////////////////////////////////
	_streak = MotionStreak::create(0.8, 10, node->getContentSize().width*2, ccWHITE, "test.png");
	_streak->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0));
	this->addChild(_streak);
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MotionStreakSpriteTestLayer::onTouchBeganss, this);
	listener->onTouchMoved = CC_CALLBACK_2(MotionStreakSpriteTestLayer::onTouchMovess, this);
	listener->onTouchEnded = CC_CALLBACK_2(MotionStreakSpriteTestLayer::onTouchEndss, this);
	listener->setSwallowTouches(true);//是否向下传递
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, node);
	return true;
	return true;
}

Scene* MotionStreakSpriteTestLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = MotionStreakSpriteTestLayer::create();
	scene->addChild(layer);
	return scene;
}

bool MotionStreakSpriteTestLayer::onTouchBeganss(Touch* touch, Event* ev)
{
	auto target = static_cast<Sprite*>(ev->getCurrentTarget());

	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	//判断触摸区域是否在目标上
	if (rect.containsPoint(locationInNode))
	{
		//label->setString("onTouchBegan......");
		//target->setOpacity(0);
		return true;
	}
	return false;
	return true;
}

void MotionStreakSpriteTestLayer::onTouchMovess(Touch* touch, Event* ev)
{
	auto target = static_cast<Sprite*>(ev->getCurrentTarget());
	target->setPosition(target->getPosition() + touch->getDelta());
	_streak->setPosition(target->getPosition());
	//label->setString("onTouchMoved......");
	Rect r1 = target->boundingBox();
	log("r1.x=%f,r1.y=%f，r1.width=%f,r1.height=%f",r1.getMinX(),r1.getMaxY(),r1.size.width,r1.size.height);
}

void MotionStreakSpriteTestLayer::onTouchEndss(Touch* touch, Event* ev)
{
	auto target = static_cast<Sprite*>(ev->getCurrentTarget());
	//target->setOpacity(0);
	//label->setString("onTouchEnded......");
}
