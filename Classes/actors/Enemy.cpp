#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "GameManager.h"
#include <algorithm>

using namespace std;

bool Enemy::init(){
    Actor::init();
    setTag(TAG_ENEMY);

    Vec2 x[] = { Vec2(43, -43), Vec2(-43, -43), Vec2(0, 50) };
    auto physicsBody = PhysicsBody::createPolygon(x, 3);
    this->setPhysicsBody(physicsBody);
    _physicsBody->setGravityEnable(false);
    _physicsBody->setCategoryBitmask(ENEMY_CATEGORY_BITMASK);
    _physicsBody->setCollisionBitmask(ENEMY_COLLISION_BITMASK);
    _physicsBody->setContactTestBitmask(ENEMY_TEST_BITMASK);

	auto sprite = Sprite::create("monster.png");
	addChild(sprite);	
    _hpLabel = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
    _hpLabel->setPosition(0,0);
    addChild(_hpLabel);    

    _totalTime = .0f;

    schedule(CC_SCHEDULE_SELECTOR(Enemy::tick), 1.0f/60.0f);

    return true;
}

Enemy* Enemy::create(Scene *pScene, Vec2 pos, int HP, EnemyMovingRole role) {
	log(GameManager::getInstance()->getDouble(SKEY_SCORE));
    auto enemy = Enemy::create();
    enemy->_scene = pScene;
    enemy->setPosition(pos);
    enemy->_startPos = pos;
    enemy->_role = role;
    enemy->_player = static_cast<Player*>(pScene->getChildByTag(TAG_PLAYER));
	enemy->_enemyHP = HP;
	enemy->showHP();
    return enemy;
}

void Enemy::onCollision(PhysicsContact &c, PhysicsBody *b) {
    if (b->getNode()->getTag() == TAG_BULLET){
        _enemyHP --;
        showHP();
        if (_enemyHP == 0){
            removeFromParentAndCleanup(true);
            double currentscore = GameManager::getInstance()->getDouble(SKEY_SCORE);
            GameManager::getInstance()->setDouble(SKEY_SCORE, currentscore + 1, false);
        }
    }

    if (b->getNode()->getTag() == TAG_PLAYER){
        removeFromParentAndCleanup(true);
    }
}

void Enemy::showHP(){
    char hp[0xf];
    sprintf(hp, "%d", _enemyHP);
    _hpLabel->setString(hp);
}

float min_float(float a, float b)
{
	if (a < b) return a;
	return b;
}

Vec2 Enemy::positionOnTime(float time){
	//Code here
    /*if (_role == EMR_LINE){
        return _startPos + (_player->getPosition() - _startPos) * .1 * time;
    } else if (_role == EMR_PARABOL){
        return Vec2(time * 50, time * time * 10);
    }*/
	float time_ = time;
	float speed = .2;
	float change = 5;
	Vec2 current_pos ;
	Vec2 goal = _player->getPosition();
	goal.x -= 350;
	current_pos = _startPos + (goal - _startPos) * speed * min_float(time_ ,10);	
	Vec2 tmp_pos = current_pos;
	time_ -= change;
	if (time_ > 0)
	{
		goal.x += 350;
		goal.y -= 350;
		current_pos = tmp_pos + (goal - tmp_pos) * speed * min_float(time_, 10);
	}
	else return current_pos;
	tmp_pos = current_pos;
	time_ -= change;
	if (time_ > 0)
	{
		goal.x += 350;
		goal.y += 350;
		current_pos = tmp_pos + (goal - tmp_pos) * speed * min_float(time_, 10);
	}
	else return current_pos;
	tmp_pos = current_pos;
	time_ -= change;
	if (time_ > 0)
	{
		current_pos = tmp_pos + (_player->getPosition() - tmp_pos) * speed * time_;
	}
	else return current_pos;
	return current_pos;
}

void Enemy::tick(float dt){
    _totalTime += dt;
    setPosition(positionOnTime(_totalTime));
}
