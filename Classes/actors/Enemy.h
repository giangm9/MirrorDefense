#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Actor.h"

class Enemy : public Actor{
public:
	virtual bool init();
	int _enemyHP;
	void tick(float dt);

	static Enemy *create(Scene* pScene, Vec2 pos);
	bool _autoMove;

	virtual void onCollision(PhysicsContact &c, PhysicsBody *b);

private:
	CREATE_FUNC(Enemy)
	void enemydestruct();
};


#endif // __EN_H__
