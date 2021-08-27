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

	//체력이 가득 찬 적기(2장)	//불이 나지 않음
	addImage("Asset/적기.bmp", 1, 281, 190, 137, 0);

	addImage("Asset/적기.bmp", 201, 281, 190, 137, 0);

	//중간 체력 (4장)	적당히 불이 남
	for (int i = 0; i < 4; ++i)
	{
		addImage("Asset/적기.bmp", 1 + 200 * i, 141, 190, 137, 1);
	}

	//낮은 체력 (4장)	불이 상당히 남
	for (int i = 0; i < 4; ++i)
	{
		addImage("Asset/적기.bmp", 1 + 200 * i, 1, 190, 137, 2);
	}
}

void Enemy::update()
{
	ChecktoMove();

	//적기 총알 발사//
	fireTimer += Time::deltaTime;

	if (fireTimer >= fireDelay)
	{
		instantiate(new EnemyBullet(getPx() + 87 , getPy() + 137), 1);
		fireTimer = .0f;
	}
	
}

void Enemy::ChecktoMove()
{
	//적기 이동 State Machine
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