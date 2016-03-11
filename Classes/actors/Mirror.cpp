#include "Mirror.h"

#define TAG_MOUSE_BODY 10


bool Mirror::init(){
	Actor::init();

	auto physicsBody = PhysicsBody::createBox(Size(100.0f, 30.0f));
	physicsBody->setGravityEnable(false);
	this->setPhysicsBody(physicsBody);


	auto sprite = Sprite::create("mirror.png");
	addChild(sprite);
	sprite->setPosition(Vec2(0,0));
	sprite->setTag(1);

	listener = EventListenerTouchOneByOne::create();
	//listener->setSwallowTouches(true);


	listener->onTouchBegan = [](Touch *touch , Event * event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		auto world = target->getScene()->getPhysicsWorld();

		if(target->getPosition().distance(touch->getLocation()) < 100){

			return true;
		}
		return false;
	};

	listener->onTouchMoved = [](Touch* touch, Event* event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		auto world = target->getScene()->getPhysicsWorld();

		//Move the position of current button sprite

		target->setPosition(target->getPosition() + touch->getDelta());
		//target->getPhysicsBody()->applyImpulse(1000*touch->getDelta());

	};

	listener->onTouchEnded = [=](Touch *touch, Event* event){		
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		target->getPhysicsBody()->retain();

	};

	return true;
}

Mirror* Mirror::create(Scene *pScene){
	auto mirror = Mirror::create();
	mirror->_scene = pScene;
	mirror->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mirror->listener, mirror);
	return mirror;
}
