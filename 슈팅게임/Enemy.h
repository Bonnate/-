#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum State { moveDown = 0, moveLeft, moveRight };		//���Ǹ� Ŭ���� ���ο� �ϸ� �ܺο��� ��ġ�� ��찡 �������... Input�� State�� ���� �����ϰԵ�

private:
	float speed;
	State state;

	float fireTimer;
	float fireDelay;

public:
	Enemy(float px, float py);
	~Enemy();

	void start();
	void update();
	
	void ChecktoMove();
	void ChecktoShoot();
};