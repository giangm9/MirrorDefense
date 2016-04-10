#include "Bullet.h"
#include <cmath>

bool Bullet::init(){
	Actor::init();
	setTag(TAG_BULLET);
	auto physicsBody = PhysicsBody::createCircle(10,PhysicsMaterial(.05,2,.1), Vec2(0,0));


	physicsBody->setCategoryBitmask(BULLET_CATEGORY_BITMASK);
	physicsBody->setCollisionBitmask(BULLET_COLLISION_BITMASK);
	physicsBody->setContactTestBitmask(BULLET_TEST_BITMASK);

	auto sprite = Sprite::create("bullet.png");
	addChild(sprite, 10);

	this->setPhysicsBody(physicsBody);
	scheduleOnce(CC_SCHEDULE_SELECTOR(Bullet::selfDestruct), 10);
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


void Bullet::selfDestruct(float dt){
	removeFromParentAndCleanup(true);
}
