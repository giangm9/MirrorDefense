#ifndef __BULLET_H__
#define __BULLET_H__

#include "Actor.h"

using namespace cocos2d;

class Bullet : public Actor
{
public:
	virtual bool init();
	Vec2 _taget;
	CREATE_FUNC(Bullet)
	static Bullet* create(Scene* pScene, Vec2 pos, Vec2 target);


};


#endif // __BULLET_H__
