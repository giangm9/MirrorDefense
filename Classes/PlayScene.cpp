#include "PlayScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"


bool PlayScene::init(){
	Scene::initWithPhysics();
	getPhysicsWorld()->setGravity(Vec2(0,-1));

	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	Point s_centre(400, 400);

	auto mirror = Mirror::create(this);
	auto mirror2 = Mirror::create(this);

	mirror->setPosition(s_centre);
	mirror2->setPosition(s_centre + Vec2(0, 200));

	addChild(mirror,1);

	addChild(mirror2,2);

	return true;
}
