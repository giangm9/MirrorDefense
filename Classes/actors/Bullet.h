#ifndef __BULLET_H__
#define __BULLET_H__

#include "Actor.h"

class Bullet : public Actor
{
public:
	virtual bool init();
	CREATE_FUNC(Bullet)

};


#endif // __BULLET_H__
