#include "Mirror.h"
#include "Bullet.h"


#define TAG_MIRROR 10


bool Mirror::init(){
	Actor::init();
	setTag(TAG_MIRROR);
	auto physicsBody = PhysicsBody::createBox(Size(200.0f, 30.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setDynamic(false);
	physicsBody->setContactTestBitmask(0xff);

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




	return true;
}

Mirror* Mirror::create(Scene *pScene){
	auto mirror = Mirror::create();
	mirror->_scene = pScene;	
	mirror->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mirror->_listener, mirror);
	return mirror;
}


void Mirror::onCollision(PhysicsContact &c, PhysicsBody *b){
	log("hi");
	if (b->getNode()->getTag() == 11){


		auto reflect = Bullet::create(getScene(), b->getNode()->getPosition(),
																	Vec2(
																		cos(CC_DEGREES_TO_RADIANS( b->getNode()->getRotation())) * -10000,
																		sin(CC_DEGREES_TO_RADIANS( b->getNode()->getRotation())) *  -10000));
		getScene()->addChild(reflect);

		b->getNode()->removeFromParentAndCleanup(true);
		log("%.2f %.2f", b->getPosition().x, b->getPosition().y);
		log("%.2f %.2f", getPhysicsBody()->getPosition().x, getPhysicsBody()->getPosition().y);
		//auto bullet = Bullet::create(_scene)
	}
}
