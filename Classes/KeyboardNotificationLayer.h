#pragma once

/************************************************************************/
/* º¸≈Ã ‰»Î                                                                     */
/************************************************************************/
#include "cocos2d.h"
USING_NS_CC;


#define FONT_NAME                       "fonts/Marker Felt.ttf"
#define FONT_SIZE                       36

class KeyboardNotificationLayer :public Layer,public IMEDelegate
{

public:
	KeyboardNotificationLayer();

	virtual void onClickTrackNode(bool bClicked) =0;

	virtual void keyboardWillShow(IMEKeyboardNotificationInfo& info);

	bool onTouchBegan(Touch  *touch, Event  *event);
	void onTouchEnded(Touch  *touch, Event  *event);
	
protected:
	Node * _trackNode;
	Vec2  _beginPos;
};


class TextFieldTTFDefaultTest : public KeyboardNotificationLayer
{
public:
	virtual bool init();
	CREATE_FUNC(TextFieldTTFDefaultTest);
public:
	virtual void onClickTrackNode(bool bClicked);
};