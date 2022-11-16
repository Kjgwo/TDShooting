#ifndef __UNIT_H__
#define __UNIT_H__

#include "stdafx.h"

class Unit : public Node {
private:
	float hp = 100;
protected:
	Sprite* spr;
	PhysicsBody* body;
public:
	static Unit* create(const Size& size, int bitmask, int tag); // �浹���� ũ�⶧���� ������ ������ �ʿ�
	virtual bool init(const Size& size, int bitmask, int tag);
	PhysicsBody* getBody();

	void setHP(float value);
	float getHP();
	void addHP(float value);

	bool isHPZero();
};


class Player : public Unit {
public:
	static Player* create();
	virtual bool init();

	virtual void removeFromParent() override;
};


class Enemy : public Unit {
public:
	static Enemy* create();
	virtual bool init();

	virtual void removeFromParent() override;
};
#endif