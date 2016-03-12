#include "Bullet.h"
#include <cmath>

bool Bullet::init(){
	Actor::init();
	setTag(11);
	auto physicsBody = PhysicsBody::createBox(Size(10.0f, 60.0f));
	physicsBody->setCategoryBitmask(1);
	physicsBody->setCollisionBitmask(0xfe);
	physicsBody->setContactTestBitmask(0xfe);
	this->setPhysicsBody(physicsBody);
}


Bullet* Bullet::create(Scene *pScene, Vec2 pos, Vec2 target){
	auto bullet = Bullet::create();
	bullet->_scene = pScene;
	bullet->setRotation(CC_RADIANS_TO_DEGREES(atan(target.x / target.y)));
	bullet->getPhysicsBody()->applyForce(target);
	bullet->setPosition(pos);
	return bullet;
}
