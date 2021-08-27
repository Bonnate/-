#pragma once

#include "GameObject.h"

class Player : public GameObject
{
private:
	float speed;
	float fireTimer;
	float fireDelay;

	//�÷��̾� �̹�����//
	Image	image[7];
	int		index;		//����� �÷��̾� �̹����� �ε��� ��ȣ(�⺻�� 3)
	float   changeImageDelay;

public:
	Player();
	Player(float px, float py);
	~Player();

	void start();
	void update();
	void draw();

	/// <summary>
	/// �÷��̾ �̵��ϱ� ���� Ű üũ �Լ��Դϴ�.
	/// </summary>
	void GetKeytoMove();
	void GetKeytoShoot();
};
