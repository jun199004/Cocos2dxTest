#include "KeyboardNotificationLayer.h"

KeyboardNotificationLayer::KeyboardNotificationLayer()
: _trackNode(0)
{
	// Register Touch Event
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(KeyboardNotificationLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(KeyboardNotificationLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}



void KeyboardNotificationLayer::keyboardWillShow(IMEKeyboardNotificationInfo& info)
{
	CCLOG("TextInputTest:keyboardWillShowAt(origin:%f,%f, size:%f,%f)",
		info.end.origin.x, info.end.origin.y, info.end.size.width, info.end.size.height);

	if (!_trackNode)
	{
		return;
	}

	auto rectTracked =_trackNode->boundingBox() ;// getRect(_trackNode);

	// if the keyboard area doesn't intersect with the tracking node area, nothing need to do.
	if (!rectTracked.intersectsRect(info.end))
	{
		return;
	}

	// assume keyboard at the bottom of screen, calculate the vertical adjustment.
	float adjustVert = info.end.getMaxY() - rectTracked.getMinY();
	CCLOG("TextInputTest:needAdjustVerticalPosition(%f)", adjustVert);

	// move all the children node of KeyboardNotificationLayer
	auto& children = getChildren();
	Node * node = 0;
	ssize_t count = children.size();
	Vec2 pos;
	for (int i = 0; i < count; ++i)
	{
		node = children.at(i);
		pos = node->getPosition();
		pos.y += adjustVert;
		node->setPosition(pos);
	}
}
bool KeyboardNotificationLayer::onTouchBegan(Touch  *touch, Event  *event)
{
	CCLOG("++++++++++++++++++++++++++++++++++++++++++++");
	_beginPos = touch->getLocation();
	return true;
}

void KeyboardNotificationLayer::onTouchEnded(Touch  *touch, Event  *event)
{
	if (!_trackNode)
	{
		return;
	}

	auto endPos = touch->getLocation();

	float delta = 5.0f;
	if (::abs(endPos.x - _beginPos.x) > delta
		|| ::abs(endPos.y - _beginPos.y) > delta)
	{
		// not click
		_beginPos.x = _beginPos.y = -1;
		return;
	}

	// decide the trackNode is clicked.
	Rect rect;
	auto point = touch->getLocation();
	CCLOG("KeyboardNotificationLayer:clickedAt(%f,%f)", point.x, point.y);

	rect = _trackNode->boundingBox();// getRect(_trackNode);
	CCLOG("KeyboardNotificationLayer:TrackNode at(origin:%f,%f, size:%f,%f)",
		rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);

	this->onClickTrackNode(rect.containsPoint(point));
	CCLOG("----------------------------------");
}


//////////////////////////////////////////////////////////////////////////
void TextFieldTTFDefaultTest::onClickTrackNode(bool bClicked)
{
	auto pTextField = (TextFieldTTF*)_trackNode;
	if (bClicked)
	{
		// TextFieldTTFTest be clicked
		CCLOG("TextFieldTTFDefaultTest:TextFieldTTF attachWithIME");
		pTextField->attachWithIME();
	}
	else
	{
		// TextFieldTTFTest not be clicked
		CCLOG("TextFieldTTFDefaultTest:TextFieldTTF detachWithIME");
		pTextField->detachWithIME();
	}
}

//void TextFieldTTFDefaultTest::onEnter()
//{
//	KeyboardNotificationLayer::onEnter();
//
//	// add TextFieldTTF
//	auto s = Director::getInstance()->getWinSize();
//
//	auto pTextField = TextFieldTTF::textFieldWithPlaceHolder("<click here for input>",
//		FONT_NAME,
//		FONT_SIZE);
//	addChild(pTextField);
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)    
//	// on android, TextFieldTTF cannot auto adjust its position when soft-keyboard pop up
//	// so we had to set a higher position to make it visable
//	pTextField->setPosition(Vec2(s.width / 2, s.height / 2 + 50));
//#else
//	pTextField->setPosition(Vec2(s.width / 2, s.height / 2));
//#endif
//
//	_trackNode = pTextField;
//}

bool TextFieldTTFDefaultTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto s = Director::getInstance()->getWinSize();
	auto pTextField = TextFieldTTF::textFieldWithPlaceHolder("<click here for input>",
		FONT_NAME,
		FONT_SIZE);
	addChild(pTextField);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)    
	// on android, TextFieldTTF cannot auto adjust its position when soft-keyboard pop up
	// so we had to set a higher position to make it visable
	pTextField->setPosition(Vec2(s.width / 2, s.height / 2 + 50));
#else
	pTextField->setPosition(Vec2(s.width / 2, s.height / 2));
#endif

	_trackNode = pTextField;
	return true;
}
