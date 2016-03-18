#include "Mirror.h"
#include "Bullet.h"

#define MIRROR_WIDTH 200
#define MIRROR_HEIGHT 20


#define TAG_MIRROR 10


bool Mirror::init(){
	Actor::init();
	setTag(TAG_MIRROR);
	auto physicsBody = PhysicsBody::createBox(Size(MIRROR_WIDTH, MIRROR_HEIGHT),PhysicsMaterial(0,.5,0));
	physicsBody->setGravityEnable(false);
	physicsBody->setDynamic(false);
	physicsBody->setContactTestBitmask(0xff);

	this->setPhysicsBody(physicsBody);

	auto sprite = Sprite::create("mirror.png");
	addChild(sprite);
	sprite->setPosition(Vec2(0,0));
	sprite->setTag(1);

	setRotation(160);

	_listener = EventListenerTouchOneByOne::create();
	//listener->setSwallowTouches(true);

	_listener->onTouchBegan = [](Touch *touch , Event * event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		return target->getPhysicsBody()->getShape(0)->containsPoint(touch->getLocation());
	};

	_listener->onTouchMoved = [](Touch* touch, Event* event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		target->getPhysicsBody()->setCategoryBitmask(0);
		//auto world = target->getScene()->getPhysicsWorld();

		//Move the position of current button sprite

		target->setPosition(target->getPosition() + touch->getDelta());

	};

	_listener->onTouchEnded = [=](Touch *touch, Event* event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		target->getPhysicsBody()->setCategoryBitmask(0xff);
		target->getPhysicsBody()->retain();

	};

	return true;
}

Mirror* Mirror::create(Scene *pScene){
	auto mirror = Mirror::create();
	mirror->_scene = pScene;	
	mirror->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mirror->_listener, mirror);
	return mirror;
}


void Mirror::onCollision(PhysicsContact &c, PhysicsBody *b){
	//log("hi");
	if (b->getNode()->getTag() == TAG_BULLET){

		//auto incommingBullet = static_cast<Bullet*>(b->getNode());
	}
}
