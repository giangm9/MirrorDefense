#include "GameManager.h"
#include "play/PlayLayer.h"



GameManager* GameManager::ms_instance = NULL;

GameManager* GameManager::getInstance (){
    if (!ms_instance){
        ms_instance = new GameManager();

        auto director = Director::getInstance();
        ms_instance->m_scene = Scene::create();
        director->runWithScene(ms_instance->m_scene);
        ms_instance->changeGameState(GSTATE_MAIN);
    }
    return ms_instance;
}




void GameManager::changeGameState (GameState gameState){
    auto layer = PlayLayer::create();
    m_scene->addChild(layer);
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
