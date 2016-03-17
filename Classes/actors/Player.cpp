#include "Player.h"
#include "Bullet.h"
#include <algorithm>


using namespace std;


bool Player::init(){
	Actor::init();
	this->setPhysicsBody(PhysicsBody::createCircle(50));
	_physicsBody->setCollisionBitmask(0xfe);
	_physicsBody->setContactTestBitmask(0xfe);

	_isShooting = false;
	schedule(CC_SCHEDULE_SELECTOR(Player::tick), .1);
	return true;
}


void Player::tick(float dt){

	if (_isShooting){
		_reloadTime += dt;
		if (_reloadTime > .5){
			_reloadTime = .0;
			float power = 10000; // its over 9000
			float x = cos(getRotation());
			float y = sin(getRotation());


			auto bullet = Bullet::create(_scene,
																	 getPosition() + Vec2(x * 10, y * 10),
																	 Vec2(x,y) * power);
			_scene->addChild(bullet);
		}

	}
}

Player* Player::create(Scene *pScene, Vec2 pos){
	auto  player = Player::create();
	player->setPosition(pos);
	player->_scene = pScene;
	player->_isShooting = true;
	player->_reloadTime = 0;
	return player;
}
