#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include <algorithm>



using namespace std;

bool Enemy::init(){
	Actor::init();
	Vec2 x[] = { Vec2(35, -35), Vec2(-35, -35), Vec2(0, 50) };
	auto physicsBody = PhysicsBody::createPolygon(x, 3);
	this->setPhysicsBody(physicsBody);


	_physicsBody->setGravityEnable(false);
	_physicsBody->setCategoryBitmask(ENEMY_CATEGORY_BITMASK);
	_physicsBody->setCollisionBitmask(ENEMY_COLLISION_BITMASK);
	_physicsBody->setContactTestBitmask(ENEMY_TEST_BITMASK);



	setTag(TAG_ENEMY);

	_enemyHP = 3;
	_hpLabel = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
	_hpLabel->setPosition(0,0);
	addChild(_hpLabel);
	showHP();
	return true;
}

Enemy* Enemy::create(Scene *pScene, Vec2 pos) {
	auto enemy = Enemy::create();
	enemy->_scene = pScene;
	enemy->setPosition(pos);
	enemy->_autoMove = true;
	Vec2 target = Vec2(640, 350) - pos;
	enemy->getPhysicsBody()->applyImpulse(target* 30);
	return enemy;
}

void Enemy::selfDestruct() {
	removeFromParentAndCleanup(true);
}

void Enemy::onCollision(PhysicsContact &c, PhysicsBody *b) {
	if (b->getNode()->getTag() == TAG_BULLET){
		_enemyHP --;
		showHP();
		if (_enemyHP == 0){
			selfDestruct();
		}
	}

	if (b->getNode()->getTag() == TAG_PLAYER){
		selfDestruct();
	}
}

void Enemy::showHP(){
	char hp[0xf];
	sprintf(hp, "%d", _enemyHP);
	_hpLabel->setString(hp);
}
