#include "framework.h"

Enemy::Enemy(float px, float py) : Animation("", "", true, px, py)
{
	this->speed = 100.0f;
	this->state = State::moveDown;

	this->fireTimer = .0f;
	this->fireDelay = 1.0f;
}

Enemy::~Enemy()
{

}

void Enemy::start()
{

	//ü���� ���� �� ����(2��)	//���� ���� ����
	addImage("Asset/����.bmp", 1, 281, 190, 137, 0);

	addImage("Asset/����.bmp", 201, 281, 190, 137, 0);

	//�߰� ü�� (4��)	������ ���� ��
	for (int i = 0; i < 4; ++i)
	{
		addImage("Asset/����.bmp", 1 + 200 * i, 141, 190, 137, 1);
	}

	//���� ü�� (4��)	���� ����� ��
	for (int i = 0; i < 4; ++i)
	{
		addImage("Asset/����.bmp", 1 + 200 * i, 1, 190, 137, 2);
	}
}

void Enemy::update()
{
	ChecktoMove();

	//���� �Ѿ� �߻�//
	fireTimer += Time::deltaTime;

	if (fireTimer >= fireDelay)
	{
		instantiate(new EnemyBullet(getPx() + 87 , getPy() + 137), 1);
		fireTimer = .0f;
	}
	
}

void Enemy::ChecktoMove()
{
	//���� �̵� State Machine
	switch (state)
	{
	case State::moveDown:
	{
		translate(0, speed * Time::deltaTime);

		if (getPy() > 150.0f)
			state = State::moveLeft;
	}
	break;

	case State::moveLeft:
	{
		translate(-speed * Time::deltaTime, 0);

		if (getPx() < 0)
			state = State::moveRight;
	}
	break;

	case State::moveRight:
	{
		translate(+speed * Time::deltaTime, 0);

		if (getPx() > WIDTH - 190)
			state = State::moveLeft;
	}
	break;
	}
}