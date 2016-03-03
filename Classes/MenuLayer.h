#ifndef _MENULAYER_H_
#define _MENULAYER_H_

#include "cocos2d.h"

using namespace cocos2d;


class MenuLayer
{
public:
  virtual bool init();

  virtual float onAppearLayer(){return 0;}
  virtual float onExitLayer(){return 0;}

  CREATE_FUNC(MenuLayer)
};


#endif //_MENULAYER_H_
