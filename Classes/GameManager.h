
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

enum StorageKey {
  SKEY_SCORE = 0,
  SKEY_HP
};


enum GameState{
  GSTATE_MAINMENU = 0,
  GSTATE_PLAY
};

class GameManager
{
public:

  void changeGameState (GameState gameState);

  double getDoubleVal (StorageKey key);

  void setDoubleVal(StorageKey key, double value, bool isSaved);

  char* getStringVal(StorageKey key);

  void setStringVal(StorageKey key, char* value, bool isSaved);

};

#endif // GAMEMANAGER_H
