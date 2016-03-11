#include "GameManager.h"
#include "PlayScene.h"



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
	auto play = PlayScene::create();
	Director::getInstance()->replaceScene(play);	
}

float GameManager::getDouble (StogareKey key){

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
