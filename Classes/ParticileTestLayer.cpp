#include "ParticileTestLayer.h"



bool ParticleTestLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////

	
	auto node = Sprite::create("CloseNormal.png");
	node->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0));
	auto system2 = ParticleSun::create();// CCParticleSystemQuad::create("ballfire.plist");
	system2->setPosition(Vec2(node->getContentSize().width / 2, node->getContentSize().height / 2.0));
	node->addChild(system2, 1);
	this->addChild(node);
	node->setOpacity(0);
	funEventTouch(node);
	return true;


	//auto node = Sprite::create("CloseNormal.png");
	//node->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0));
	//this->addChild(node);
	////////////////////////////////////////////////////////////////////////////
	//_streak = MotionStreak::create(0.8, 10, node->getContentSize().width, ccWHITE, "CloseNormal.png");
	//_streak->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0));
	//this->addChild(_streak, 1);
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(ParticleTestLayer::onTouchBeganss, this);
	//listener->onTouchMoved = CC_CALLBACK_2(ParticleTestLayer::onTouchMovess, this);
	//listener->onTouchEnded = CC_CALLBACK_2(ParticleTestLayer::onTouchEndss, this);
	//listener->setSwallowTouches(true);//是否向下传递
	//this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, node);
	//return true;


	//////////////////////////////////////////////////////////////////////////

	ParticleSystem* system;
	ActionTypes thetype = kSun;
	switch (thetype)
	{
	case kExplosion:
		system = ParticleExplosion::create();
		break;
	case kFire:
		system = ParticleFire::create();
		break;
	case kFireworks:
		system = ParticleFireworks::create();
		break;
	case kFlower:
		system = ParticleFlower::create();
		break;
	case kGalaxy:
		system = ParticleGalaxy::create();
		break;
	case kMeteor:
		system = ParticleMeteor::create();
		break;
	case kRain:
		system = ParticleRain::create();
		break;
	case kSmoke:
		system = ParticleSmoke::create();
		break;
	case kSnow:
		system = ParticleSnow::create();
		break;
	case kSpiral:
		system = ParticleSpiral::create();
		break;
	case kSun:
		system = ParticleSun::create();
		break;
	}


	system->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));

	this->addChild(system);

	return true;
}


Scene* ParticleTestLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = ParticleTestLayer::create();
	scene->addChild(layer);
	return scene;
}

void ParticleTestLayer::funEventTouch(Sprite* sprite)
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ParticleTestLayer::onTouchBeganss, this);
	listener->onTouchMoved = CC_CALLBACK_2(ParticleTestLayer::onTouchMovess, this);
	listener->onTouchEnded = CC_CALLBACK_2(ParticleTestLayer::onTouchEndss, this);
	listener->setSwallowTouches(true);//是否向下传递
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sprite);
}

bool ParticleTestLayer::onTouchBeganss(Touch* touch, Event* ev)
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

void ParticleTestLayer::onTouchMovess(Touch* touch, Event* ev)
{
	auto target = static_cast<Sprite*>(ev->getCurrentTarget());
	target->setPosition(target->getPosition() + touch->getDelta());
	//_streak->setPosition(target->getPosition());
	//label->setString("onTouchMoved......");
}

void ParticleTestLayer::onTouchEndss(Touch* touch, Event* ev)
{
	auto target = static_cast<Sprite*>(ev->getCurrentTarget());
	//target->setOpacity(0);
	//label->setString("onTouchEnded......");
}
