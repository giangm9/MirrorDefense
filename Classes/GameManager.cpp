#include "GameManager.h"
#include "PlayScene.h"
#include "MenuScene.h"
#include "StatusLayer.h"
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
		auto play = PlayScene::create();
		Director::getInstance()->replaceScene(play);
		/*auto status = StatusLayer::create();
		statusSize = status->getContentSize();
		status::setPosition(Vec2((origin.x + visibleSize.width - statusSize.width / 2), 0));
		play->addChild(status);*/
	
	}/*else if (gameEvent == GE_GAMEOVER){
		auto gameover = ResultLayer::create();
		gameover::setPosition(Vec2::ZERO);
		play->addChild(gameover);
	}*/
	//all above comment will be code in gameEvent when the mention layer is completed
	//required play layer can be pause for event gameover
}


double GameManager::getDouble (StorageKey key){
	if (key == SKEY_HP) {
		return PlayerHP;
	}
	return 0;
}

void GameManager::setDouble (StorageKey key,
	                            double value,
	                            bool isStoraged){
	if (key == SKEY_HP) {
		PlayerHP = value;
		if (isStoraged) {

		}
	}
}

void GameManager::getString (StorageKey key,
	                            char* str){
}

void GameManager::setString (StorageKey key,
	                            char* str,
	                            bool isStoraged){

}
