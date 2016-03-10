#ifndef __EN_H__
#define

#include "Actor.h"

class Enemy : public Actor{
public:
	bool virtual init();

	CREATE_FUNC(Enemy)
};


#endif // __EN_H__
