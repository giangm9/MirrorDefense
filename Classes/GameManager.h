#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "cocos2d.h"
#include "MenuLayer.h"

using namespace cocos2d;

enum GameEvent{
		GE_MAIN = 0,
		GE_PLAY,
		GE_GAMEOVER,
};

enum StogareKey{
    SKEY_HP = 0
};

/*managing game's state and some resources*/
class GameManager 
{

public:
    static GameManager* getInstance ();
		void onGameEvent (GameEvent gameEvent);

    float getDouble (StogareKey key);
    void setDouble (StogareKey key, double value, bool isStogared);

    void getString (StogareKey key, char* str);
    void setString (StogareKey key,char* str, bool isStogared);

private:
    static GameManager* ms_instance;
		GameEvent m_currentEvent;
    Scene* m_scene;

};


#endif //_GAMEMANAGER_H_
