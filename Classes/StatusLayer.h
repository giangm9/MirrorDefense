#ifndef _STATUSLAYER_H_
#define _STATUSLAYER_H_


#include "cocos2d.h"

using namespace cocos2d;

class StatusLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(StatusLayer)

    Label *_hpLabel;
    void updateStatus(float dt = 0 );
};


#endif //_STATUSLAYER_H_
