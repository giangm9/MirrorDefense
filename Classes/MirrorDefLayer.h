
#ifndef MIRRORDEFLAYER_H
#define MIRRORDEFLAYER_H

#include "GameManager.h"
#include <cocos2d.h>

using namespace cocos2d;

class MirrorDefLayer : public Node
{
public:



	/**
	 * will be call right after initial function
	 */
	virtual void onAppear ();

	virtual void onExit ();



	virtual void setManager (GameManager gm);
};

#endif // MIRRORDEFLAYER_H
