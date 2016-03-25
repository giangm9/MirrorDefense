#include "PlayScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"


bool PlayScene::init(){
	Scene::initWithPhysics();
	//  Physic initial
	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	getPhysicsWorld()->setGravity(Vec2(0,0));
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PlayScene::onContactBegin,
																									this);
	_eventDispatcher->addEventListenerWithFixedPriority(contactListener, 10);

	// creat some actors for testing
	for (int i = 0; i < 5; i++){
		auto mirror = Mirror::create(this);
		mirror->setPosition(Vec2(i*100 + 200, 400));
		addChild(mirror);

	}

	auto player = Player::create(this, Vec2(640,350));
	addChild(player);	
	for (int i = 0; i < 10; i++){
		auto enemy = Enemy::create(this, Vec2(100 + 100 * i, 100));
		addChild(enemy);
	}




	return true;
}


bool PlayScene::onContactBegin(PhysicsContact &contact){	
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB){
		(static_cast<Actor*>(nodeA))->onCollision(contact,
																							nodeB->getPhysicsBody());
	}
	if (nodeA && nodeB){
		(static_cast<Actor*>(nodeB))->onCollision(contact,
																							nodeA->getPhysicsBody());
	}

	return true;
}


