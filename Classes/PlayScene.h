#ifndef _PLAYLAYER_H_
#define _PLAYLAYER_H_

#include "cocos2d.h"
#include "actors/Mirror.h"
#include "actors/Bullet.h"
#include "actors/Player.h"
#include "actors/Enemy.h"

using namespace cocos2d;

class PlayScene : public Scene
{

public:	
	virtual bool init();

	bool onContactBegin(PhysicsContact&);
	void onPauseButtonCallback(Ref*);

	CREATE_FUNC(PlayScene)
	float _totalTime;
	int _HP;
	int _totalEnemy;
	bool _isPause;
	void tick(float dt);
private:

};


#endif //_PLAYLAYER_H_
