#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "physics/CCPhysicsBody.h"
#include "cocos2d.h"

using namespace cocos2d;

class Actor : public Node{
public:
	bool virtual bool init();
	onCollision(Fixture f);

	CREATE_FUNC(Actor)
protected:
	void createRotator();
	Scene *_scene;

};

#endif //__ACTOR_H__
