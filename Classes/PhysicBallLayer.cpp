
#include "PhysicBallLayer.h"



PhysicBallLayer::PhysicBallLayer()
{

}

PhysicBallLayer::~PhysicBallLayer()
{

}


Scene* PhysicBallLayer::createScene()
{
	//创建有物理空间的场景
	Scene* scene = Scene::createWithPhysics();

	//设置Debug模式，你会看到物体的表面被线条包围，主要为了在调试中更容易地观察
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	PhysicBallLayer* layer = PhysicBallLayer::create();
	//把空间保持我们创建的层中，就是上面所说m_world的作用，方便后面设置空间的参数
	// layer->setPhyWorld(scene->getPhysicsWorld());

	scene->addChild(layer);
	return scene;


}

bool PhysicBallLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	_ballOne = Sprite::create("Ball.jpg");
	_ballOne->setPosition(200, 200);
	//创建物体，并且物体的形状为圆形，第一参数为半径，第二个参数为物体材质
	//第三个参数为边的厚度,就是在Debug模式下看到的物体外面线条的厚度，默认为0
	PhysicsBody* ballBodyOne = PhysicsBody::createCircle(_ballOne->getContentSize().width / 2, PHYSICSBODY_MATERIAL_DEFAULT);
	//是否设置物体为静态
	//ballBodyOne->setDynamic(false);
	//设置物体的恢复力
	ballBodyOne->getShape(0)->setRestitution(1.0f);
	////设置物体的摩擦力
	ballBodyOne->getShape(0)->setFriction(0.0f);
	////设置物体密度
	ballBodyOne->getShape(0)->setDensity(1.0f);
	//设置质量
	//ballBodyOne->getShape(0)->setMass(5000);
	//设置物体是否受重力系数影响
	ballBodyOne->setGravityEnable(false);
	ballBodyOne->setCategoryBitmask(0x00000001);
	ballBodyOne->setCollisionBitmask(0x00000011);
	ballBodyOne->setContactTestBitmask(0x00000011);
	//设置物体的冲力
	Vect force = Vect(500000.0f, 500000.0f);
	//把物体添加到精灵中
	_ballOne->setPhysicsBody(ballBodyOne);
	//设置标志
	_ballOne->setTag(1);
	this->addChild(_ballOne);
	ballBodyOne->applyImpulse(force);

	//设置第二个球
	_ballTwo= Sprite::create("Ball.jpg");
	_ballTwo->setPosition(500, 500);
	PhysicsBody* ballBodyTwo = PhysicsBody::createCircle(_ballTwo->getContentSize().width / 2, PHYSICSBODY_MATERIAL_DEFAULT);
	//是否设置物体为静态
	//ballBodyTwo->setDynamic(false);
	ballBodyTwo->getShape(0)->setRestitution(1.0f);
	ballBodyTwo->getShape(0)->setFriction(0.0f);
	ballBodyTwo->getShape(0)->setDensity(1.0f);

	ballBodyTwo->setGravityEnable(false);
	ballBodyTwo->setCategoryBitmask(0x00000001);
	ballBodyTwo->setCollisionBitmask(0x00000011);
	ballBodyTwo->setContactTestBitmask(0x00000010);
	force = Vect(-500000.0f, -500000.0f);
	_ballTwo->setPhysicsBody(ballBodyTwo);
	_ballTwo->setTag(2);
	ballBodyTwo->applyImpulse(force);
	this->addChild(_ballTwo);

	//创建一个盒子，用来碰撞
	Sprite* edgeSpace = Sprite::create();
	PhysicsBody* boundBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	boundBody->getShape(0)->setFriction(0.0f);
	boundBody->getShape(0)->setRestitution(1.0f);
	boundBody->setCategoryBitmask(0x00000010);
	boundBody->setCollisionBitmask(0x00000001);
	boundBody->setContactTestBitmask(0x00000001);
	edgeSpace->setPhysicsBody(boundBody);
	edgeSpace->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(edgeSpace);
	edgeSpace->setTag(0);

	return true;
}


void PhysicBallLayer::onEnter()
{
	Layer::onEnter();
	//添加监听器
	auto contactListener = EventListenerPhysicsContact::create();
	//设置监听器的碰撞开始函数
	contactListener->onContactBegin = CC_CALLBACK_1(PhysicBallLayer::onContactBegin, this);
	//添加到事件分发器中
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

}


bool PhysicBallLayer::onContactBegin(const PhysicsContact& contact)
{
	log("oncontactbegin");
	//Sprite* spriteA=(Sprite*)contact.getShapeA()->getBody()->getNode();
	//Sprite* spriteB=(Sprite*)contact.getShapeB()->getBody()->getNode();
	//int tagA=spriteA->getTag();
	//int tagB=spriteB->getTag();
	//if(tagA==1&&tagB==2||tagA==2&&tagB==1)
	//{
	//	spriteA->removeFromParent();
	//	spriteB->removeFromParent();
	//}
	return true;
}