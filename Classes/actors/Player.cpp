#include "Player.h"
#include "Bullet.h"
#include <algorithm>


using namespace std;


bool Player::init(){
	Actor::init();
	this->setPhysicsBody(PhysicsBody::createCircle(50));


	_physicsBody->setCollisionBitmask(0xfe);
	_physicsBody->setContactTestBitmask(0xfe);
	_physicsBody->setGravityEnable(false);

	_isShooting = false;
	schedule(CC_SCHEDULE_SELECTOR(Player::tick), .1);
	return true;
}


void Player::tick(float dt){

	if (_isShooting){
		_reloadTime += dt;
		if (_reloadTime > .2){
			_reloadTime = .0;
			float power = 10000; // its over 9000
			float x = -cos(CC_DEGREES_TO_RADIANS(getRotation()));
			float y = sin(CC_DEGREES_TO_RADIANS(getRotation()));


			auto bullet = Bullet::create(_scene,
																	 getPosition() + Vec2(x * 10, y * 10),
																	 Vec2(x,y) * power);
			_scene->addChild(bullet);
		}

	}
}

Player* Player::create(Scene *pScene, Vec2 pos){
	auto  player = Player::create();
	player->_scene = pScene;
	player->createRotator();
	player->setPosition(pos);

	player->_isShooting = true;
	player->_reloadTime = 0;

	return player;
}

void Player::createRotator(){
	// Create Rotator
	_rotator = Sprite::create("rotator.png");
	_rotator->setPosition(getPosition());
	_rotator->setAnchorPoint(Vec2(-2, .5));
	_scene->addChild(_rotator);


	auto _rotateListener = EventListenerTouchOneByOne::create();
	//_rotateListener->setSwallowTouches(true);

	_rotateListener->onTouchBegan = [](Touch *touch , Event * event){
		auto target = static_cast<Player*>(event->getCurrentTarget());
		auto sprite = target->_rotator;

		return sprite->getBoundingBox()
				.containsPoint(touch->getLocation());
	};

	_rotateListener->onTouchMoved = [](Touch* touch, Event* event){

		auto target = static_cast<Player*>(event->getCurrentTarget());
		float dx = touch->getLocation().x - target->getPosition().x;
		float dy = touch->getLocation().y - target->getPosition().y;
		target->setRotation(CC_RADIANS_TO_DEGREES(atan2(-dy,dx)));

		target->_rotator->setRotation(CC_RADIANS_TO_DEGREES(atan2(-dy,dx)));
	};

	_rotateListener->onTouchEnded = [=](Touch *touch, Event* event){

	};

	getEventDispatcher()->addEventListenerWithSceneGraphPriority(_rotateListener, this);
}

void Player::setPosition(Vec2 pos){
	Actor::setPosition(pos);
	if (_rotator){
		_rotator->setPosition(getPosition());
	}
}
