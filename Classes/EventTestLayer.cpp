#include "EventTestLayer.h"

USING_NS_CC;

Scene* EventTestLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = EventTestLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene

    return scene;
}

// on "init" you need to initialize your instance
bool EventTestLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(EventTestLayer::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	m_label = Label::create();
	m_label->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height - 100));
	this->addChild(m_label);
	m_label->setString("test");

	auto sprite01 = Sprite::create("CyanSquare.png");
	sprite01->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0)+Vec2(-80,80));
	this->addChild(sprite01, 0);
	funEventTouch(sprite01);

	auto sprite02 = Sprite::create("MagentaSquare.png");
	sprite02->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0) + Vec2(0,0));
	this->addChild(sprite02, 0);
	funEventTouch(sprite02,1);

	auto sprite03 = Sprite::create("YellowSquare.png");
	sprite03->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0) + Vec2(80, 80));
	this->addChild(sprite03, 0);
	funEventTouch(sprite03,2);

	keyboardEventTouch();

	auto sprite04 = Sprite::create("YellowSquare.png");
	sprite04->setPosition(Vec2(visibleSize.width / 2.0, visibleSize.height / 2.0) + Vec2(80, 80+80));
	this->addChild(sprite04, 0);
	//funEventMouse(sprite04);



	//自定義事件
	//funEventCustom();

	//2秒後派發一次自定義事件，測試
	//schedule(schedule_selector(HelloWorld::dispatcherCustomEvents), 2.0f);


	funEventAcceleration();

    
    return true;
}


void EventTestLayer::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void EventTestLayer::funEventTouch(Sprite* sprite,int nindx)
{
	//this->_eventDispatcher->removeAllEventListeners();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(EventTestLayer::onTouchBeganss, this);
	listener->onTouchMoved = CC_CALLBACK_2(EventTestLayer::onTouchMovess, this);
	listener->onTouchEnded = CC_CALLBACK_2(EventTestLayer::onTouchEndss, this);
	listener->onTouchCancelled = CC_CALLBACK_2(EventTestLayer::onTouchCancless, this);
	listener->setSwallowTouches(true);//是否向下传递
	switch (nindx)
	{
	case 0:
		this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sprite);
		break;
	default:
		this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite);
		break;
	}
	
}

void EventTestLayer::onTouchCancless(Touch* touch, Event* ev)
{
	//label->setString("onTouchCancelled......");
}

void EventTestLayer::onTouchEndss(Touch* touch, Event* ev)
{
	auto target = static_cast<Sprite*>(ev->getCurrentTarget());
	target->setOpacity(255);
	//label->setString("onTouchEnded......");
}

void EventTestLayer::onTouchMovess(Touch* touch, Event* ev)
{
	auto target = static_cast<Sprite*>(ev->getCurrentTarget());
	target->setPosition(target->getPosition() + touch->getDelta());
	//label->setString("onTouchMoved......");
}

bool EventTestLayer::onTouchBeganss(Touch* touch, Event* ev)
{
	auto target = static_cast<Sprite*>(ev->getCurrentTarget());

	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	//判断触摸区域是否在目标上
	if (rect.containsPoint(locationInNode))
	{
		//label->setString("onTouchBegan......");
		target->setOpacity(255);
		return true;
	}
	return false;
	return true;
}

void EventTestLayer::keyboardEventTouch()
{
	this->_eventDispatcher->removeAllEventListeners();

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(EventTestLayer::onKeyPressedss, this);
	listener->onKeyReleased = CC_CALLBACK_2(EventTestLayer::onKeyReleasedss, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

void EventTestLayer::onKeyPressedss(EventKeyboard::KeyCode keycode, Event* ev)
{
	char txt[100] = {};
	//sprintf_s(txt, "key %d is Pressed!", (int)keycode);
	snprintf(txt,100,"key %d is Pressed!", (int)keycode);
	m_label->setString(txt);
}

void EventTestLayer::onKeyReleasedss(EventKeyboard::KeyCode keycode, Event* ev)
{
	m_label->setString("key is Released!");
}

void EventTestLayer::funEventMouse(Sprite* sprite)
{
	//this->_eventDispatcher->removeAllEventListeners();

	auto listener = EventListenerMouse::create();
	listener->onMouseDown = CC_CALLBACK_1(EventTestLayer::onMouseDownss, this);
	listener->onMouseMove = CC_CALLBACK_1(EventTestLayer::onMouseMovess, this);
	listener->onMouseUp = CC_CALLBACK_1(EventTestLayer::onMouseUpss, this);
	listener->onMouseScroll = CC_CALLBACK_1(EventTestLayer::onMouseScrollss, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sprite);

}

void EventTestLayer::onMouseDownss(Event* ev)
{
	m_label->setString("onMouseDown!");
}
void EventTestLayer::onMouseMovess(Event* ev)
{
	m_label->setString("onMouseMove!");
}
void EventTestLayer::onMouseUpss(Event* ev)
{
	m_label->setString("onMouseUp!");
}
void EventTestLayer::onMouseScrollss(Event* ev)
{
	m_label->setString("onMouseScroll!");
}


void EventTestLayer::funEventCustom()
{
	auto listener = EventListenerCustom::create("custom_event_1", CC_CALLBACK_1(EventTestLayer::onEventCustom, this));
	this->_eventDispatcher->addEventListenerWithFixedPriority(listener, 1);//添加到事件分發器
}

void EventTestLayer::dispatcherCustomEvents(float at)
{
	//派發事件custom_event_1  事件內容為字符串custom event test!
	this->_eventDispatcher->dispatchCustomEvent("custom_event_1",(void*) "custom event test!");
}

void EventTestLayer::onEventCustom(EventCustom* event)
{
	auto data = static_cast<char*>(event->getUserData());
	static auto count = 0;
	count++;
	char txt[100] = {};
	//sprintf_s(txt, "%d,%s", (int)count,data);
	snprintf(txt,100, "%d,%s", (int)count, data);
	m_label->setString(txt);
}

void EventTestLayer::funEventAcceleration()
{
	//啟動硬件設備
	Device::setAccelerometerEnabled(true);

	auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(EventTestLayer::onAcceleration, this));
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void EventTestLayer::onAcceleration(Acceleration* acc, Event* event)
{
	char str[100] = {};
	snprintf(str, 100, "x:%2d,y:%2d,z:%2d,timestamp:%2d", acc->x, acc->y, acc->z, acc->timestamp);
	//snprintf_l(str, "x:%2d,y:%2d,z:%2d,timestamp:%2d", acc->x, acc->y, acc->z, acc->timestamp);
	//log(str);
	//cocos2d::log(str);
	m_label->setString(str);

}