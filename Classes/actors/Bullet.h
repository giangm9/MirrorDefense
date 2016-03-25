#ifndef __BULLET_H__
#define __BULLET_H__

#include "Actor.h"

using namespace cocos2d;

class Bullet : public Actor
{
public:
	virtual bool init();
	Vec2 _taget;	
	static Bullet* create(Scene* pScene, Vec2 pos, Vec2 target);
private:
	void selfDestruct(float dt);
	CREATE_FUNC(Bullet)
};


#endif // __BULLET_H__
