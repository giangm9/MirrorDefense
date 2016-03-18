#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "physics/CCPhysicsBody.h"
#include "cocos2d.h"

using namespace cocos2d;

class Actor : public Node{
public:
	virtual bool init(){return true;}

	virtual void onCollision(PhysicsContact &c, PhysicsBody *b){}

	Scene *getScene(){return _scene;}

	CREATE_FUNC(Actor)
protected:


	Scene *_scene;
	EventListenerTouchOneByOne *_rotateListener;

};

#endif //__ACTOR_H__
