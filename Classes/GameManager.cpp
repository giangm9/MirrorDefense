#include "GameManager.h"
#include "PlayScene.h"



GameManager* GameManager::ms_instance = NULL;

GameManager* GameManager::getInstance (){
    if (!ms_instance){
        ms_instance = new GameManager();

        auto director = Director::getInstance();
				ms_instance->m_scene = Scene::create();
        director->runWithScene(ms_instance->m_scene);
				ms_instance->onGameEvent(GE_PLAY);
    }
    return ms_instance;
}


void GameManager::onGameEvent  (GameEvent gameEvent){
	auto play = PlayScene::create();
	Director::getInstance()->replaceScene(play);	
	if (gameEvent == GE_MAIN){
		auto menu = MenuScene::create();
		Director::getInstance()->replaceScene(menu);
	}else if (gameEvent == GE_PLAY){
		auto play = PlayScene::create();
		Director::getInstance()->replaceScene(play);
	}//else if (gameEvent == GE_GAMEOVER){
//		auto gameover= GameOverLayer::create();
	//}
}


float GameManager::getDouble (StogareKey key){
	return 0;
}

void GameManager::setDouble (StogareKey key,
	                            double value,
	                            bool isStogared){

}

void GameManager::getString (StogareKey key,
	                            char* str){
}

void GameManager::setString (StogareKey key,
	                            char* str,
	                            bool isStogared){

}
