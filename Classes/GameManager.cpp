#include "GameManager.h"
#include "PlayScene.h"
#include "MenuScene.h"
#include "StatusLayer.h"
#include "ResultLayer.h"

USING_NS_CC;

GameManager* GameManager::ms_instance = NULL;


GameManager* GameManager::getInstance (){
    if (!ms_instance){
        ms_instance = new GameManager();

        auto director = Director::getInstance();
				ms_instance->m_scene = Scene::create();
        director->runWithScene(ms_instance->m_scene);
				ms_instance->onGameEvent(GE_MAIN);
    }
    return ms_instance;
}


void GameManager::onGameEvent  (GameEvent gameEvent){
	//auto menu = MenuScene::create();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//Director::getInstance()->replaceScene(menu);	
	if (gameEvent == GE_MAIN){
		auto menu = MenuScene::create();
		Director::getInstance()->replaceScene(menu);
	}else if (gameEvent == GE_PLAY){
		_playerScore = 0;
		auto play = PlayScene::create();
		Director::getInstance()->replaceScene(play);
        auto status = StatusLayer::create();
        Size statusSize = status->getContentSize();
        status->setPosition(Vec2((origin.x + visibleSize.width - statusSize.width / 2), 0));
        play->addChild(status);	
	}else if (gameEvent == GE_GAMEOVER){
		auto scene = Director::getInstance()->getRunningScene();
		auto gameover = ResultLayer::create();
		Size statusSize = gameover->getContentSize();
		gameover->setPosition(Vec2((origin.x + visibleSize.width - statusSize.width / 2), 0));
		scene->addChild(gameover, 100);
	}
	//all above comment will be code in gameEvent when the mentioned layer is completed
	//required play layer can be pause for event gameover
}


double GameManager::getDouble (StorageKey key){
	if (key == SKEY_HP) {
		return _playerHP;
	}
	else if (key == SKEY_SCORE) {
		return _playerScore;
	}
	return 0;
}

void GameManager::setDouble (StorageKey key,
	                            double value,
	                            bool isStoraged){
	if (key == SKEY_HP) {
		_playerHP = value;
		if (isStoraged) {

		}
	}
	else if (key == SKEY_SCORE) {
		_playerScore = value;
	}

}

void GameManager::getString (StorageKey key,
	                            char* str){
}

void GameManager::setString (StorageKey key,
	                            char* str,
	                            bool isStoraged){

}
