#include "framework.h"

PlayerLaser::PlayerLaser(float px, float py, int angle) : Sprite("", "", true, px, py)
{
	this->speed = 250.0f;
	this->angle = angle;
}

PlayerLaser::~PlayerLaser()
{

}

void PlayerLaser::start()
{
	setImage("Asset/·¹ÀÌÀú.bmp");
}

void PlayerLaser::update()
{
	float dist = speed * Time::deltaTime;

	switch (angle)
	{
	case 0:
		translate(0, -dist);
		break;

	case -1:
		translate(-0.1f, -dist);
		break;

	case +1:
		translate(+0.1f, -dist);
		break;
	}
	
}
