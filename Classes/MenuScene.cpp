#include "MenuScene.h"
#include "GameManager.h"

USING_NS_CC;

bool MenuScene::init()
{
	Scene::init();
	
	auto layer = MenuLayer::create();
	
	this->addChild(layer);
	
	return true;
}

bool MenuLayer::init()
{
	if  ( !Layer::init() ){return false;}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto sprite = Sprite::create("hello.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite, 0);

	auto playButton = MenuItemImage::create("play_button.png","play_button.png",CC_CALLBACK_1(MenuLayer::menuPlayCallback, this));
	playButton->setPosition(Vec2((origin.x + visibleSize.width) / 2,( origin.y + visibleSize.height )/ 2));
	
	auto menu = Menu::create(playButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	
	return true;
}

void MenuLayer::menuPlayCallback(Ref* pSender)
{
	GameManager::getInstance()->onGameEvent(GE_PLAY);
}
