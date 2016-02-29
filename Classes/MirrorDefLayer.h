#ifndef _MIRRORDEFLAYER_H_
#define _MIRRORDEFLAYER_H_

#include "cocos2d.h"

using namespace cocos2d;

class MirrorDefLayer : public Node
{

public:
	virtual float onAppearLayer() = 0;
	virtual float onExitLayer () = 0;
    virtual bool init() = 0;
};


#endif //_MIRRORDEFLAYER_H_
