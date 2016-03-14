#include "PlayScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"


bool PlayScene::init(){
	Scene::initWithPhysics();

	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	getPhysicsWorld()->setGravity(Vec2(0,0));
	Point s_centre(800, 300);

	auto mirror = Mirror::create(this);

	for (int i = 0; i < 1; i++){
		auto bullet = Bullet::create(this,
																 Vec2(200 + 20*i, 600), Vec2(10000 + CCRANDOM_0_1() * 10000, -10000));
		addChild(bullet);
	}


	mirror->setPosition(s_centre);
	addChild(mirror, 2);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PlayScene::onContactBegin,
																									this);
	_eventDispatcher->addEventListenerWithFixedPriority(contactListener, 10);

	return true;
}


bool PlayScene::onContactBegin(PhysicsContact &contact){
	//log("hi");
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
