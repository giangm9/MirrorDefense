#include "ResultLayer.h"


bool ResultLayer::init(){
    Layer::init();

    auto gameoverText = Label::createWithTTF("Game Over~", "fonts/Marker Felt.ttf", 24);
    gameoverText->setPosition(40, 100);
    addChild(gameoverText);



    return true;
}
