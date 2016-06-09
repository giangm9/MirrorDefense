#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Actor.h"
#include "Player.h"

enum EnemyMovingRole{
	EMR_LINE = 0,
	EMR_PARABOL
};

class Enemy : public Actor{
public:
	virtual bool init();
	int _enemyHP;		

	static Enemy *create(Scene* pScene, Vec2 pos, int HP,
						 EnemyMovingRole role = EMR_LINE);
	bool _autoMove;

	virtual void onCollision(PhysicsContact &c, PhysicsBody *b);

	Player *_player;
	Vec2 _startPos;
	void tick(float dt);
	EnemyMovingRole _role;
	Vec2 positionOnTime(float time);


private:
	CREATE_FUNC(Enemy)

	Label * _hpLabel;
	void showHP();

	float _totalTime;
};


#endif // __EN_H__
