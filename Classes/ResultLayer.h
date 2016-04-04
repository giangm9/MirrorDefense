#include "cocos2d.h"


using namespace cocos2d;


class ResultLayer: public Layer{
public:
    virtual bool init();
    CREATE_FUNC(ResultLayer)

    void replayButtonCallback(cocos2d::Ref* pSender);
};
