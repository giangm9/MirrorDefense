#include "Mirror.h"


#define TAG_MIRROR 10


bool Mirror::init(){
	Actor::init();
	setTag(TAG_MIRROR);
	auto physicsBody = PhysicsBody::createBox(Size(200.0f, 30.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setDynamic(false);

	this->setPhysicsBody(physicsBody);



	auto sprite = Sprite::create("mirror.png");
	addChild(sprite);
	sprite->setPosition(Vec2(0,0));
	sprite->setTag(1);

	setRotation(135);

	_listener = EventListenerTouchOneByOne::create();
	//listener->setSwallowTouches(true);

	_listener->onTouchBegan = [](Touch *touch , Event * event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		auto world = target->getScene()->getPhysicsWorld();

		if(target->getPosition().distance(touch->getLocation()) < 100){

			return true;
		}
		return false;
	};

	_listener->onTouchMoved = [](Touch* touch, Event* event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		auto world = target->getScene()->getPhysicsWorld();

		//Move the position of current button sprite

		target->setPosition(target->getPosition() + touch->getDelta());

	};

	_listener->onTouchEnded = [=](Touch *touch, Event* event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		target->getPhysicsBody()->retain();

	};

	_physicListener = EventListenerPhysicsContact::create();
	_physicListener->onContactBegin = CC_CALLBACK_1(Mirror::onContactBegin, this);



	return true;
}

Mirror* Mirror::create(Scene *pScene){
	auto mirror = Mirror::create();
	mirror->_scene = pScene;
	pScene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mirror->_physicListener, pScene);
	mirror->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mirror->_listener, mirror);
	return mirror;
}


bool Mirror::onContactBegin(PhysicsContact &contact){
	log("hi");
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	Node *mirror = NULL;
	Node *bullet = NULL;
	if (!nodeA || !nodeB) return false;

	log("%d %d", nodeA->getTag(), nodeB->getTag());
	if (nodeA->getTag() == TAG_MIRROR && nodeB->getTag() == 11 ){
		mirror = nodeA;
		bullet = nodeB;
	} else if(nodeA->getTag() == 11  && nodeB->getTag() == TAG_MIRROR ){
		mirror = nodeB;
		bullet = nodeA;
	}

	if (mirror && bullet){
		bullet->removeFromParentAndCleanup(true);

	}
	return true;
}
