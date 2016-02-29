#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

enum GameState{

};

enum StogareKey{

};

/*managing game's state and some resources*/
class GameManager 
{

public:
	void enterTheGame ();
	GameManager getInstance ();
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



};


#endif //_GAMEMANAGER_H_
