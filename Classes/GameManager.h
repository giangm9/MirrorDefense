#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "cocos2d.h"

//#include "MenuLayer.h"

//#include "MenuLayer.h"
#include "MenuScene.h"

using namespace cocos2d;

enum GameEvent{
	GE_MAIN = 0,
	GE_PLAY,
	GE_GAMEOVER,

};

enum StorageKey{
	SKEY_HP = 0,
	SKEY_SCORE
};

/*managing game's state and some resources*/
class GameManager : public cocos2d::Scene
{

public:
	static GameManager* getInstance ();
	void onGameEvent (GameEvent gameEvent);

	double getDouble (StorageKey key);
	void setDouble (StorageKey key, double value, bool isStoraged);

	void getString (StorageKey key, char* str);
	void setString (StorageKey key,char* str, bool isStoraged);

private:
	static GameManager* ms_instance;
	GameEvent m_currentEvent;
	Scene* m_scene;
	double _playerHP;
	double _playerScore;

};


#endif //_GAMEMANAGER_H_
