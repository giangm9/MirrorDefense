#include "Mirror.h"
#include "Bullet.h"

#define MIRROR_WIDTH 200
#define MIRROR_HEIGHT 20


#define TAG_ROTATOR 9



bool Mirror::init(){
	Actor::init();
	setTag(TAG_MIRROR);
	auto physicsBody = PhysicsBody::createBox(Size(MIRROR_WIDTH, MIRROR_HEIGHT),PhysicsMaterial(0,.5,0));
	physicsBody->setGravityEnable(false);
	physicsBody->setDynamic(false);

	physicsBody->setCategoryBitmask(MIRROR_CATEGORY_BITMASK);
	physicsBody->setCollisionBitmask(MIRROR_COLLISION_BITMASK);
	physicsBody->setContactTestBitmask(MIRROR_TEST_BITMASK);
	physicsBody->setContactTestBitmask(0xff);

	this->setPhysicsBody(physicsBody);

	auto sprite = Sprite::create("mirror.png");
	addChild(sprite);
	sprite->setPosition(Vec2(0,0));
	sprite->setTag(1);

	_listener = EventListenerTouchOneByOne::create();
	_listener->setSwallowTouches(true);

	_listener->onTouchBegan = [](Touch *touch , Event * event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		return target->getPhysicsBody()->getShape(0)->containsPoint(touch->getLocation());
	};

	_listener->onTouchMoved = [](Touch* touch, Event* event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		target->getPhysicsBody()->setCategoryBitmask(0);
		target->setPosition(target->getPosition() + touch->getDelta());

	};

	_listener->onTouchEnded = [=](Touch *touch, Event* event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		target->getPhysicsBody()->setCategoryBitmask(0xff);
		target->getPhysicsBody()->retain();
	};
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listener, this);


	return true;
}

Mirror* Mirror::create(Scene *pScene){
	auto mirror = Mirror::create();
	mirror->_scene = pScene;		
	mirror->createRotator();
	return mirror;
}


void Mirror::onCollision(PhysicsContact &c, PhysicsBody *b){
	//log("hi");
	if (b->getNode()->getTag() == TAG_BULLET){

		//auto incommingBullet = static_cast<Bullet*>(b->getNode());
	}
}

void Mirror::createRotator(){
	// Create Rotator
	_rotator = Sprite::create("rotator.png");
	_rotator->setPosition(getPosition());
	_rotator->setAnchorPoint(Vec2(-2, .5));
	_scene->addChild(_rotator);


	auto _rotateListener = EventListenerTouchOneByOne::create();
	//_rotateListener->setSwallowTouches(true);

	_rotateListener->onTouchBegan = [](Touch *touch , Event * event){
		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		auto sprite = target->_rotator;

		return sprite->getBoundingBox()
				.containsPoint(touch->getLocation());
	};

	_rotateListener->onTouchMoved = [](Touch* touch, Event* event){

		auto target = static_cast<Mirror*>(event->getCurrentTarget());
		float dx = touch->getLocation().x - target->getPosition().x;
		float dy = touch->getLocation().y - target->getPosition().y;
		target->setRotation(CC_RADIANS_TO_DEGREES(atan2(-dy,dx)));

		//target->_rotator->setRotation(CC_RADIANS_TO_DEGREES(atan2(-dy,dx)));
	};

	_rotateListener->onTouchEnded = [=](Touch *touch, Event* event){

	};

	getEventDispatcher()->addEventListenerWithSceneGraphPriority(_rotateListener, this);
}


void Mirror::setPosition(Vec2 pos){
	Actor::setPosition(pos);
	_rotator->setPosition(getPosition());
}


void Mirror::setRotation(float rotation){
	Actor::setRotation(rotation);
	_rotator->setRotation(rotation);
}
