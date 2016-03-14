#include "Bullet.h"
#include <cmath>

bool Bullet::init(){
	Actor::init();
	setTag(11);
	auto physicsBody = PhysicsBody::createCircle(10,PhysicsMaterial(.05,2,.1), Vec2(0,0));


	physicsBody->setCategoryBitmask(1);
	physicsBody->setCollisionBitmask(0xfe);
	physicsBody->setContactTestBitmask(0xfe);

	this->setPhysicsBody(physicsBody);
	return true;
}


Bullet* Bullet::create(Scene *pScene, Vec2 pos, Vec2 target){	
	auto bullet = Bullet::create();
	bullet->_scene = pScene;
	bullet->setRotation(CC_RADIANS_TO_DEGREES(atan(target.x / target.y)));
	bullet->getPhysicsBody()->applyImpulse(target);
	bullet->setPosition(pos);
	bullet->_taget = Vec2(target);
	return bullet;
}
