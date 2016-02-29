#ifndef _MENULAYER_H_
#define _MENULAYER_H_

#include "cocos2d.h"
#include "MirrorDefLayer.h"

using namespace cocos2d;


class MenuLayer : public MirrorDefLayer
{
  virtual bool init();

  virtual float onAppearLayer();
  virtual float onExitLayer();

  CREATE_FUNC(MenuLayer)
};


#endif //_MENULAYER_H_
