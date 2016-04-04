#include "StatusLayer.h"
#include "GameManager.h"

bool StatusLayer::init(){
    Layer::init();
    _hpLabel = Label::createWithTTF("HP :", "fonts/Marker Felt.ttf", 24);
    _hpLabel->setPosition(30, 600);
    addChild(_hpLabel);

    _scoreLabel = Label::createWithTTF("Score : ", "fonts/Marker Felt.ttf", 24);
    _scoreLabel->setPosition(30, 540);
    addChild(_scoreLabel);

    updateStatus();
    schedule(CC_SCHEDULE_SELECTOR(StatusLayer::updateStatus), 1.0/60.0);
    return true;
}


void StatusLayer::updateStatus(float){
    char buff[0xf];
    sprintf(buff, "HP : %.0f", GameManager::getInstance()->getDouble(SKEY_HP));
    _hpLabel->setString(buff);
    sprintf(buff, "Score : %.0f", GameManager::getInstance()->getDouble(SKEY_SCORE));
    _scoreLabel->setString(buff);

}
