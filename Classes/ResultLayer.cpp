#include "ResultLayer.h"
#include "GameManager.h"

USING_NS_CC;

bool ResultLayer::init(){
    Layer::init();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto replayButton = MenuItemImage::create("replay.png", "replay.png", CC_CALLBACK_1(ResultLayer::replayButtonCallback, this));
	replayButton->setPosition(Vec2(origin.x, (origin.y + visibleSize.height) / 2));
	
	auto replay = Menu::create(replayButton, NULL);
	replay->setPosition(Vec2::ZERO);
	this->addChild(replay, 100);
	
	auto gameoverText = Label::createWithTTF("~Game Over~", "fonts/Marker Felt.ttf", 84);
    gameoverText->setPosition(10, 548);
    addChild(gameoverText, 100);

	auto quitButton = MenuItemImage::create("quit.png", "quit.png", CC_CALLBACK_1(ResultLayer::quitButtonCallback, this));
	quitButton->setPosition(Vec2(origin.x, (origin.y + visibleSize.height)/2 - 100));

	auto quit = Menu::create(quitButton, NULL);
	quit->setPosition(Vec2::ZERO);
	this->addChild(quit, 100);

    return true;
}

void ResultLayer::replayButtonCallback(Ref* pSender)
{
	GameManager::getInstance()->onGameEvent(GE_PLAY);
}

void ResultLayer::quitButtonCallback(Ref* pSender)
{
	Director::getInstance()->end();
}