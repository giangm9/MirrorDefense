#include "MenuScene.h"
#include "GameManager.h"

USING_NS_CC;

bool MenuScene::init()
{
	auto scene = Scene::create();
	
	auto layer = MenuLayer::create();
	
	scene->addChild(layer);
	
	return scene;
}

bool MenuLayer::init()
{
	if  ( !Layer::init() )
    {
        return false;
    }
	
	auto visibleSize = Size(300, 400);
    auto origin = Vec2(300,400);
	
	auto playButton = MenuItemImage::create("play_button.png","play_button.png",CC_CALLBACK_1(MenuLayer::menuPlayCallback, this));
	playButton->setPosition((origin.x - playButton->getContentSize().width)/ 2, (origin.y - playButton->getContentSize().height) /2);
	
	auto menu = Menu::create(playButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	
	return true;
}

void MenuLayer::menuPlayCallback(Ref* pSender)
{
	GameManager::getInstance()->onGameEvent(GE_PLAY);
}