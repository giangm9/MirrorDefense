#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Actor.h"

class Player : public Actor{
public:
	virtual bool init();

	CREATE_FUNC(Player)
};

#endif //__PLAYER_H__
