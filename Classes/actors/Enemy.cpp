#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include <algorithm>

#define TAG_ENEMY 14

using namespace std;

bool Enemy::init(){
	Actor::init();
	Vec2 x[] = { Vec2(25, -25), Vec2(-25, -25), Vec2(0, 50) };
	auto physicsBody = PhysicsBody::createPolygon(x, 3);
	this->setPhysicsBody(physicsBody);

	_physicsBody->setGravityEnable(false);
	_physicsBody->setDynamic(false);
	_physicsBody->setContactTestBitmask(0xff);
	_physicsBody->setCollisionBitmask(0xfe);
	setTag(TAG_ENEMY);

	auto sprite = Sprite::create("Enemy.png");
	this->addChild(sprite);
	sprite->setPosition(Vec2(0, 0));
	sprite->setTag(17);
	schedule(CC_SCHEDULE_SELECTOR(Enemy::tick), .1);
	int _enemyHP = 3;

	bool _autoMove = false;

	return true;
}

Enemy* Enemy::create(Scene *pScene, Vec2 pos) {
	auto enemy = Enemy::create();
	enemy->_scene = pScene;
	enemy->setPosition(pos);
	enemy->_autoMove = true;

	return enemy;
}

void Enemy::tick(float dt) {
	Vec2 playerPos = Vec2(640, 350);
	if (_autoMove) {
		Vec2 distanceVector = playerPos - this->getPosition();
		Vec2 moveVector = Vec2(50,distanceVector.y*50/distanceVector.x);
		auto gotoAttack = MoveBy::create(.1, moveVector);
		this->runAction(gotoAttack);
	}
}

void Enemy::enemydestruct() {
	removeFromParentAndCleanup(true);
}

void Enemy::onCollision(PhysicsContact &c, PhysicsBody *b) {
	
}