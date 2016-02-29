#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "cocos2d.h"
#include "MenuLayer.h"

using namespace cocos2d;

enum GameState{
  STATE_MAIN = 0,
};

enum StogareKey{

};

/*managing game's state and some resources*/
class GameManager 
{

public:
    static GameManager* getInstance ();
	void changeGameState (GameState gameState);
	float getDouble (StogareKey key);
	void setDouble (StogareKey key,
	                double value,
                    bool isStogared);
	void getString (StogareKey key,
	                char* str);
	void setString (StogareKey key,
	                char* str,
	                bool isStogared);

private:
    static GameManager* ms_instance;
    GameState m_currentState;
    Scene* m_scene;

};


#endif //_GAMEMANAGER_H_
