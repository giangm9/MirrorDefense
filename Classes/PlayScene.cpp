#include "PlayScene.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"



bool PlayScene::init(){
	Scene::initWithPhysics();

	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	CCLOG("hi");
	Point s_centre(400, 400);


	auto physicsBody = PhysicsBody::createBox(Size(65.0f, 81.0f), PhysicsMaterial(0.1f, 1.0f, 0.0f));


	physicsBody->setDynamic(false);

	//create a sprite
	auto sprite = Sprite::create("monster.png");
	sprite->setPosition(s_centre);
	addChild(sprite);
	//apply physicsBody to the sprite
	sprite->setPhysicsBody(physicsBody);

	//add five dynamic body
	for (int i = 0; i < 5; ++i)
	{
		physicsBody = PhysicsBody::createBox(Size(65.0f, 81.0f),
																				 PhysicsMaterial(0.1f, 1.0f, 0.0f));

		//set the body isn't affected by the physics world's gravitational force
		physicsBody->setGravityEnable(false);

		//set initial velocity of physicsBody
		physicsBody->setVelocity(Vec2(cocos2d::random(-500.0,500.0),
																	cocos2d::random(-500.0,500.0)));
		//physicsBody->setTag(DRAG_BODYS_TAG);

		sprite = Sprite::create("monster.png");
		sprite->setPosition(Vec2(s_centre.x + cocos2d::random(-300,300),
														 s_centre.y + cocos2d::random(-300,300)));
		sprite->setPhysicsBody(physicsBody);

		addChild(sprite);
	}
	return true;
}


