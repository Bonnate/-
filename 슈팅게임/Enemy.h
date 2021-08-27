#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum State { moveDown = 0, moveLeft, moveRight };		//정의를 클래스 내부에 하면 외부에서 겹치는 경우가 사라진다... Input의 State랑 따로 동작하게됨

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