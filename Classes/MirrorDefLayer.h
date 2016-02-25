
#ifndef MIRRORDEFLAYER_H
#define MIRRORDEFLAYER_H

#include <string>
#include "GameManager.h"
/******************************* Abstract Class ****************************
MirrorDefLayer does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class MirrorDefLayer
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
