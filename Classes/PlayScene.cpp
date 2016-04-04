#include "GameManager.h"
#include "PlayScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"

#define PI 3.1416

bool PlayScene::init(){
    Scene::initWithPhysics();

    //  Physic initial
    getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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
    Player* player = (Player*)getChildByTag(TAG_PLAYER);
    if (player->_hitPoint == 0){
        GameManager::getInstance()->onGameEvent(GE_GAMEOVER);
    }

    _totalTime += dt;
    if (_totalTime > 1 && _totalTime < 2) {
        Vec2 cornors[] = {Vec2(0,768), Vec2(1024, 768),
                          Vec2(1024, 0), Vec2(0,0)};

        auto enemy = Enemy::create(this, cornors[rand() % 4]);
        addChild(enemy);
        _totalTime = .0;
    }
}
