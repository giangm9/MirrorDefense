#ifndef __MIRROR_H__
#define __MIRROR_H__

#include "Actor.h"

class Mirror : public Actor{
public:
	virtual bool init();

	static Mirror* create(Scene* scene);
	CREATE_FUNC(Mirror)
	EventListenerTouchOneByOne *listener;

};

#endif //__MIRROR_H__
