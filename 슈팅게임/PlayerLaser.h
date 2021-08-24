#pragma once

#include "Sprite.h"

class PlayerLaser : public Sprite
{
private:
	float speed;
	int angle;

public:
	PlayerLaser(float px, float py, int angle = 0);
	~PlayerLaser();

	void start();
	void update();

};
