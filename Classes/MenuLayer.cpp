#include "MenuLayer.h"
#include "GameManager.h"

bool MenuLayer::init(){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    addChild(label);

		GameManager::getInstance()->onGameEvent(GE_PLAY);
    return true;
}




