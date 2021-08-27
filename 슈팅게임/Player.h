#pragma once

#include "GameObject.h"

class Player : public GameObject
{
private:
	float speed;
	float fireTimer;
	float fireDelay;

	//플레이어 이미지들//
	Image	image[7];
	int		index;		//출력할 플레이어 이미지의 인덱스 번호(기본값 3)
	float   changeImageDelay;

public:
	Player();
	Player(float px, float py);
	~Player();

	void start();
	void update();
	void draw();

	/// <summary>
	/// 플레이어를 이동하기 위한 키 체크 함수입니다.
	/// </summary>
	void GetKeytoMove();
	void GetKeytoShoot();
};
