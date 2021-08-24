#pragma once

#include "Sprite.h"

class Player : public Sprite
{
private:
	float speed;
	float fireTimer;
	float fireDelay;

public:
	Player();
	Player(float px, float py);
	~Player();

	void start();
	void update();

	/// <summary>
	/// 플레이어를 이동하기 위한 키 체크 함수입니다.
	/// </summary>
	void GetKeytoMove();
	void GetKeytoShoot();
};
