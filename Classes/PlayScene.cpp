#include "GameManager.h"
#include "PlayScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"

#define PI 3.1416

bool PlayScene::init(){
    Scene::initWithPhysics();

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto sprite = Sprite::create("background.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite, 0);


    //  Physic initial
    getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
    getPhysicsWorld()->setGravity(Vec2(0,0));
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(PlayScene::onContactBegin,this);
    _eventDispatcher->addEventListenerWithFixedPriority(contactListener, 10);

    // Player
    auto player = Player::create(this, Vec2(640,350));
    addChild(player);

    // Mirrors
    for (int i = 0; i < 4; i++){
        auto mirror = Mirror::create(this);
        mirror->setPosition(Vec2(640 + 300 * sin(i * PI/2 + PI/4),
                                 350 + 300 * cos(i * PI/2 + PI/4)));
        mirror->setRotation(i * 90 + 45);
        addChild(mirror);
    }

    _totalTime = 0;
	_HP = 30;
	_totalEnemy = 0;
    schedule(CC_SCHEDULE_SELECTOR(PlayScene::tick), 1.0f/60.0f);
    return true;
}


bool PlayScene::onContactBegin(PhysicsContact &contact){
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();


    if (nodeA && nodeB){
        (static_cast<Actor*>(nodeA))->onCollision(contact,nodeB->getPhysicsBody());
    }
    if (nodeA && nodeB){
        (static_cast<Actor*>(nodeB))->onCollision(contact,nodeA->getPhysicsBody());
    }
    return true;
}


void PlayScene::tick(float dt){
	//Code here
    Player* player = (Player*)getChildByTag(TAG_PLAYER);
    if (player->_hitPoint == 0){
		GameManager::getInstance()->onGameEvent(GE_GAMEOVER);
		return;
	}

    _totalTime += dt;
    if (_totalTime > 1 && _totalTime < 2) {
		Vec2 pos;
		/*while (1)
		{
			pos.x = rand() % 1024;
			pos.y = rand() % 768;
			if (getChildByTag(TAG_PLAYER)->getPosition().distance(pos) > 350) break;
		}*/
		if (_totalEnemy == 50)
		{
			_HP += 10;
			_totalEnemy = 0;
		}
		pos = getChildByTag(TAG_PLAYER)->getPosition();
		pos.y += 350;
		auto enemy = Enemy::create(this, pos , _HP);
        addChild(enemy);
		++_totalEnemy;
        _totalTime = .0;
    }
}
