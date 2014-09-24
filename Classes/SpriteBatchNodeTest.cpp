#include "SpriteBatchNodeTest.h"



bool SpriteBatchNodeLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//CCTextureCache::getInstance()->addImage("CloseNormal.png");
	//CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey("CloseNormal.png");
	//SpriteBatchNode *bulletBatchNode = SpriteBatchNode::createWithTexture(texture);
	//for (int i = 0; i < 1000;i++)
	//{
	//	float xpos = CCRANDOM_0_1()*visibleSize.width;
	//	float ypos = CCRANDOM_0_1()*visibleSize.height;
	//	Sprite* sprite = Sprite::createWithTexture(texture);
	//	bulletBatchNode->addChild(sprite);
	//	//this->addChild(sprite);
	//	sprite->setPosition(Vec2(xpos,ypos));
	//}
	//this->addChild(bulletBatchNode);
//////////////////////////////////////////////////////////////////////////
	auto node = MyNode::create();
	for (int i = 0; i < 1000;i++)
	{
		float xpos = CCRANDOM_0_1()*visibleSize.width;
		float ypos = CCRANDOM_0_1()*visibleSize.height;
		Sprite* sprite = Sprite::create("CloseNormal.png");
		//Sprite* sprite2 = Sprite::create("CloseSelected.png");
		node->addChild(sprite);
		//this->addChild(sprite2);
		sprite->setPosition(Vec2(xpos,ypos));
	}
	Sprite* sprite2 = Sprite::create("CloseSelected.png");
	node->addChild(sprite2);
	this->addChild(node);
	return true;
}

Scene* SpriteBatchNodeLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = SpriteBatchNodeLayer::create();
	scene->addChild(layer);
	return scene;
}

bool MyNode::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;
}
