#ifndef __MIRROR_H__
#define __MIRROR_H__

#include "Actor.h"

class Mirror : public Actor{
public:
	virtual bool init();	

	virtual void onCollision(PhysicsContact &c, PhysicsBody *b);
	virtual void setPosition(Vec2 pos);
	virtual void setRotation(float rotation);

	static Mirror* create(Scene* scene);
	void createRotator();
	Sprite* _rotator;
	CREATE_FUNC(Mirror)
	EventListenerTouchOneByOne *_listener;

};

#endif //__MIRROR_H__
