#include "StatusLayer.h"
#include "GameManager.h"

bool StatusLayer::init(){
    Layer::init();
    _hpLabel = Label::createWithTTF("HP :", "fonts/Marker Felt.ttf", 48);
    _hpLabel->setPosition(30, 600);
    _hpLabel->setColor(Color3B(240, 15, 15));

    addChild(_hpLabel);

    _scoreLabel = Label::createWithTTF("Score : ", "fonts/Marker Felt.ttf", 48);
    _scoreLabel->setPosition(30, 500);
    _scoreLabel->setColor(Color3B(240, 15, 15));
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
