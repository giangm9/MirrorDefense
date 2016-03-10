#ifndef __MIRROR_H__
#define __MIRROR_H__

#include "Actor.h"

class Mirror : public Actor{
public:
	virtual bool init();

	CREATE_FUNC(Mirror)
};

#endif //__MIRROR_H__
