#include "Player.h"
#include "Bullet.h"
#include "PlayScene.h"
#include "GameManager.h"
#include <algorithm>


using namespace std;


bool Player::init(){
    Actor::init();
    setTag(TAG_PLAYER);
    this->setPhysicsBody(PhysicsBody::createCircle(50));


    _physicsBody->setCategoryBitmask(PLAYER_CATEGORY_BITMASK);
    _physicsBody->setCollisionBitmask(PLAYER_COLLISION_BITMASK);
    _physicsBody->setContactTestBitmask(PLAYER_TEST_BITMASK);
    _physicsBody->setGravityEnable(false);

	auto sprite = Sprite::create("head_tank.png");
	addChild(sprite);

    _isShooting = false;
    schedule(CC_SCHEDULE_SELECTOR(Player::tick), .1);

    _hitPoint = 10;

    _hpLabel = Label::createWithTTF("", "fonts/Marker Felt.ttf", 24);
    showHP();
    addChild(_hpLabel);
    return true;
}


void Player::tick(float dt){
        if (((PlayScene*)getScene())->_isPause) return;
    if (_isShooting){
        _reloadTime += dt;
        if (_reloadTime > 1){
            _reloadTime = .0;
            float power = 10000; // its over 9000
            float x = -cos(CC_DEGREES_TO_RADIANS(getRotation()));
            float y = sin(CC_DEGREES_TO_RADIANS(getRotation()));
			
			for (int i = 0; i < 2; i++) {
				auto bullet = Bullet::create(_scene, getPosition() + Vec2(x * 20 * i, y * 20 * i), Vec2(x, y) * power);
				_scene->addChild(bullet);
			}
        }

    }
}

Player* Player::create(Scene *pScene, Vec2 pos){
    auto  player = Player::create();
    player->_scene = pScene;
    player->createRotator();
    player->setPosition(pos);

    player->_isShooting = true;
    player->_reloadTime = 0;

    return player;
}

void Player::createRotator(){
    // Create Rotator
    _rotator = Sprite::create("rotator.png");
    _rotator->setPosition(getPosition());
    _rotator->setAnchorPoint(Vec2(-2, .5));
    _scene->addChild(_rotator, 10);


    auto _rotateListener = EventListenerTouchOneByOne::create();
    //_rotateListener->setSwallowTouches(true);

    _rotateListener->onTouchBegan = [](Touch *touch , Event * event){
        auto target = static_cast<Player*>(event->getCurrentTarget());
        auto sprite = target->_rotator;

        return sprite->getBoundingBox()
                .containsPoint(touch->getLocation());
    };

    _rotateListener->onTouchMoved = [](Touch* touch, Event* event){

        auto target = static_cast<Player*>(event->getCurrentTarget());
        float dx = touch->getLocation().x - target->getPosition().x;
        float dy = touch->getLocation().y - target->getPosition().y;
        target->setRotation(CC_RADIANS_TO_DEGREES(atan2(-dy,dx)));

        target->_rotator->setRotation(CC_RADIANS_TO_DEGREES(atan2(-dy,dx)));
    };

    _rotateListener->onTouchEnded = [=](Touch *touch, Event* event){

    };

    getEventDispatcher()->addEventListenerWithSceneGraphPriority(_rotateListener, this);
}

void Player::setPosition(Vec2 pos){
    Actor::setPosition(pos);
    if (_rotator){
        _rotator->setPosition(getPosition());
    }
}

void Player::showHP(){
    GameManager::getInstance()->setDouble(SKEY_HP, (float) _hitPoint, false);
    char hp[0xf];
    sprintf(hp, "%d", _hitPoint);
    _hpLabel->setString(hp);
	_hpLabel->setPosition(0, 50);
	_hpLabel->setColor(Color3B(146, 0, 58));
}

void Player::onCollision(PhysicsContact &c, PhysicsBody *b){
    if (b->getNode()->getTag() == TAG_ENEMY){
        _hitPoint --;
        showHP();
        if (_hitPoint == 0){
            GameManager::getInstance()->onGameEvent(GE_GAMEOVER);
        }
    }
}
