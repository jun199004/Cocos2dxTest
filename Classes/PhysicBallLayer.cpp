
#include "PhysicBallLayer.h"



PhysicBallLayer::PhysicBallLayer()
{

}

PhysicBallLayer::~PhysicBallLayer()
{

}


Scene* PhysicBallLayer::createScene()
{
	//����������ռ�ĳ���
	Scene* scene = Scene::createWithPhysics();

	//����Debugģʽ����ῴ������ı��汻������Χ����ҪΪ���ڵ����и����׵ع۲�
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	PhysicBallLayer* layer = PhysicBallLayer::create();
	//�ѿռ䱣�����Ǵ����Ĳ��У�����������˵m_world�����ã�����������ÿռ�Ĳ���
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
	//�������壬�����������״ΪԲ�Σ���һ����Ϊ�뾶���ڶ�������Ϊ�������
	//����������Ϊ�ߵĺ��,������Debugģʽ�¿������������������ĺ�ȣ�Ĭ��Ϊ0
	PhysicsBody* ballBodyOne = PhysicsBody::createCircle(_ballOne->getContentSize().width / 2, PHYSICSBODY_MATERIAL_DEFAULT);
	//�Ƿ���������Ϊ��̬
	//ballBodyOne->setDynamic(false);
	//��������Ļָ���
	ballBodyOne->getShape(0)->setRestitution(1.0f);
	////���������Ħ����
	ballBodyOne->getShape(0)->setFriction(0.0f);
	////���������ܶ�
	ballBodyOne->getShape(0)->setDensity(1.0f);
	//��������
	//ballBodyOne->getShape(0)->setMass(5000);
	//���������Ƿ�������ϵ��Ӱ��
	ballBodyOne->setGravityEnable(false);
	ballBodyOne->setCategoryBitmask(0x00000001);
	ballBodyOne->setCollisionBitmask(0x00000011);
	ballBodyOne->setContactTestBitmask(0x00000011);
	//��������ĳ���
	Vect force = Vect(500000.0f, 500000.0f);
	//��������ӵ�������
	_ballOne->setPhysicsBody(ballBodyOne);
	//���ñ�־
	_ballOne->setTag(1);
	this->addChild(_ballOne);
	ballBodyOne->applyImpulse(force);

	//���õڶ�����
	_ballTwo= Sprite::create("Ball.jpg");
	_ballTwo->setPosition(500, 500);
	PhysicsBody* ballBodyTwo = PhysicsBody::createCircle(_ballTwo->getContentSize().width / 2, PHYSICSBODY_MATERIAL_DEFAULT);
	//�Ƿ���������Ϊ��̬
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

	//����һ�����ӣ�������ײ
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
	//��Ӽ�����
	auto contactListener = EventListenerPhysicsContact::create();
	//���ü���������ײ��ʼ����
	contactListener->onContactBegin = CC_CALLBACK_1(PhysicBallLayer::onContactBegin, this);
	//��ӵ��¼��ַ�����
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