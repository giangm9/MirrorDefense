#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Actor.h"

class Player : public Actor{
public:
	virtual bool init();
	int _hitPoint;
	void tick(float dt);
	static Player *create(Scene* pScene, Vec2 pos);

	bool _isShooting;
	float _reloadTime;

	virtual void setPosition(Vec2 pos);
	void createRotator();
	Sprite * _rotator;

	virtual void onCollision(PhysicsContact &c, PhysicsBody *b);
private:
	CREATE_FUNC(Player)

	Label * _hpLabel;
	void showHP();

};

#endif //__PLAYER_H__
