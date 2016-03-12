#ifndef __MIRROR_H__
#define __MIRROR_H__

#include "Actor.h"

class Mirror : public Actor{
public:
	virtual bool init();

	virtual void onCollision(PhysicsContact &c, PhysicsBody *b);

	static Mirror* create(Scene* scene);
	CREATE_FUNC(Mirror)
	EventListenerTouchOneByOne *_listener;

};

#endif //__MIRROR_H__
