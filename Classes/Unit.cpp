#include "stdafx.h"
#include "Unit.h"

Unit * Unit::create(const Size & size, int bitmask, int tag)
{
	auto ret = new Unit();
	if (ret && ret->init(size, bitmask, tag)) ret->autorelease();
	else CC_SAFE_DELETE(ret);
	return ret;
}

bool Unit::init(const Size & size, int bitmask, int tag)
{
	if (!Node::init()) return false;

	body = PhysicsBody::createBox(size);
	body->setTag(tag);
	body->setCollisionBitmask(0);
	body->setContactTestBitmask(bitmask);
	addComponent(body);
	body->setRotationEnable(false);


	return true;
}

PhysicsBody * Unit::getBody()
{
	return body;
}

void Unit::setHP(float value)
{
	this->hp = value;
}

float Unit::getHP()
{
	return this->hp;
}

void Unit::addHP(float value)
{
	setHP(getHP() + value);
}

bool Unit::isHPZero()
{
	return getHP() <= 0.0f;
}

Player * Player::create()
{
	auto ret = new Player();
	if (ret && ret->init()) ret->autorelease();
	else CC_SAFE_DELETE(ret);
	return ret;
}

bool Player::init()
{
	if (!Unit::init(Size(75, 75), PLAYER_MASK, TAG_PLAYER)) return false;

	addChild(spr = Sprite::create("res/playerShip1_orange.png"));

	Sprite* tail = Sprite::create("res/Effects/fire11.png");
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("res/Effects/fire11.png");
	animation->addSpriteFrameWithFile("res/Effects/fire12.png");
	animation->addSpriteFrameWithFile("res/Effects/fire13.png");
	animation->addSpriteFrameWithFile("res/Effects/fire14.png");
	animation->addSpriteFrameWithFile("res/Effects/fire15.png");
	animation->addSpriteFrameWithFile("res/Effects/fire16.png");
	animation->addSpriteFrameWithFile("res/Effects/fire17.png");

	animation->setDelayPerUnit(0.125f);
	Animate* animate = Animate::create(animation);
	tail->runAction(RepeatForever::create(animate));
	tail->setPosition(Vec2(0, -60));

	addChild(tail);

	setHP(100);
	return true;
}

Enemy * Enemy::create()
{
	auto ret = new Enemy();
	if (ret && ret->init()) ret->autorelease();
	else CC_SAFE_DELETE(ret);
	return ret;
}

bool Enemy::init()
{
	if (!Unit::init(Size(75, 75), ENEMY_MASK, TAG_ENEMY)) return false;


	addChild(spr = Sprite::create("res/ufoRed.png"));

	setHP(50);

	return true;
}
