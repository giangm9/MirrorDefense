#include "PlayScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"


bool PlayScene::init(){
	Scene::initWithPhysics();

	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	getPhysicsWorld()->setGravity(Vec2(0,-9));

	for (int i =0; i< 3; i++){
		auto mirror = Mirror::create(this);
		mirror->setPosition(Vec2(i*100 + 200, 400));
		addChild(mirror);

		mirror->setRotation(120*i);
	}



	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PlayScene::onContactBegin,
																									this);
	_eventDispatcher->addEventListenerWithFixedPriority(contactListener, 10);
	schedule(CC_SCHEDULE_SELECTOR(PlayScene::tick), 0.3f);
	return true;
}

void PlayScene::tick(float dt){

	float power = 10000; // its over 9000

	auto bullet = Bullet::create(this,
															 Vec2(0 + 20, 400), Vec2(1.0f, 0.00f) * power);

	addChild(bullet);


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
