#ifndef _MENUSCENE_H_
#define _MENUSCENE_H_



#include "cocos2d.h"

using namespace cocos2d;


class MenuScene : public Scene
{
public:
	virtual bool init();
	CREATE_FUNC(MenuScene)
private:

};

class MenuLayer : public Layer
{

public:	
	//static cocos2d::Scene* createScene();
	virtual bool init();
	void menuPlayCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(MenuLayer)
private:

};


#endif //_MENU_LAYER_H_
