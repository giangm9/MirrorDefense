#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "physics/CCPhysicsBody.h"
#include "cocos2d.h"

#define TAG_PLAYER 11
#define TAG_BULLET 12
#define TAG_MIRROR 13
#define TAG_ENEMY  14

/*
 * Bit mask category
 * Player : 0001
 * Bullet : 0010
 * Enemy  : 0100
 * Mirror : 1000
 *
 * Collision
 *     m e b p
 * p   0 0 0 0 = 0
 * b   1 0 0 0 = 8
 * e   0 0 0 0 = 0
 * m   0 0 1 0 = 2
 *
 * Test
 *     m e b p
 * p   0 1 0 0 = 4
 * b   0 1 0 0 = 4
 * e   0 0 1 1 = 3
 * m   0 0 0 0 = 0
*/

#define PLAYER_CATEGORY_BITMASK 0x1
#define PLAYER_COLLISION_BITMASK 0x0
#define PLAYER_TEST_BITMASK 0x4

#define BULLET_CATEGORY_BITMASK 0x2
#define BULLET_COLLISION_BITMASK 0x8
#define BULLET_TEST_BITMASK 0x4

#define ENEMY_CATEGORY_BITMASK 0x4
#define ENEMY_COLLISION_BITMASK 0x0
#define ENEMY_TEST_BITMASK 0x3

#define MIRROR_CATEGORY_BITMASK 0x8
#define MIRROR_COLLISION_BITMASK 0x2
#define MIRROR_TEST_BITMASK 0x0


using namespace cocos2d;

class Actor : public Node{
public:
    virtual bool init(){return true;}

    virtual void onCollision(PhysicsContact &c, PhysicsBody *b){}

    Scene *getScene(){return _scene;}

    CREATE_FUNC(Actor)
    protected:


        Scene *_scene;
    EventListenerTouchOneByOne *_rotateListener;

};

#endif //__ACTOR_H__
