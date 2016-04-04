#include "StatusLayer.h"
#include "GameManager.h"

bool StatusLayer::init(){
    Layer::init();
    _hpLabel = Label::createWithTTF("HP :", "fonts/Marker Felt.ttf", 24);
    _hpLabel->setPosition(30, 600);
    addChild(_hpLabel);
    updateStatus();

    schedule(CC_SCHEDULE_SELECTOR(StatusLayer::updateStatus), 1.0/60.0);
    return true;
}


void StatusLayer::updateStatus(float){
    char hpText[0xf];
    sprintf(hpText, "HP : %.0f", GameManager::getInstance()->getDouble(SKEY_HP));
    _hpLabel->setString(hpText);
}
