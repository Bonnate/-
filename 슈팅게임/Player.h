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
	/// �÷��̾ �̵��ϱ� ���� Ű üũ �Լ��Դϴ�.
	/// </summary>
	void GetKeytoMove();
	void GetKeytoShoot();
};
