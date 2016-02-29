#ifndef _PLAYLAYER_H_
#define _PLAYLAYER_H_

#include "MirrorDefLayer.h"


class PlayLayer : public MirrorDefLayer
{

public:
    virtual bool init();
    CREATE_FUNC(PlayLayer)

    virtual float onAppearLayer(){return 0;}
    virtual float onExitLayer(){return 0;}

};


#endif //_PLAYLAYER_H_
