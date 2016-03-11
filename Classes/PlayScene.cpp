#include "PlayScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"


bool PlayScene::init(){
	Scene::initWithPhysics();	

	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	getPhysicsWorld()->setGravity(Vec2(0,0));
	Point s_centre(100, 400);

	auto mirror = Mirror::create(this);

	for (int i = 0; i < 10; i++){
		auto bullet = Bullet::create(this, Vec2(200 + 20*i, 600), Vec2(10000 + CCRANDOM_0_1() * 10000, -10000));
		addChild(bullet);
	}

	mirror->setPosition(s_centre);


	addChild(mirror,1);


	return true;
}
