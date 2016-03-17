#ifndef _PLAYLAYER_H_
#define _PLAYLAYER_H_

#include "cocos2d.h"
#include "actors/Mirror.h"
#include "actors/Bullet.h"
#include "actors/Player.h"

using namespace cocos2d;

class PlayScene : public Scene
{

public:	
	virtual bool init();

	bool onContactBegin(PhysicsContact&);
	CREATE_FUNC(PlayScene)	

	void tick(float dt);
private:

};


#endif //_PLAYLAYER_H_
