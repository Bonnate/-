#include "framework.h"

PlayerLaser::PlayerLaser(float px, float py) : Sprite("", "", true, px, py)
{
	this->speed = 250.0f;
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
	translate(0, -dist);
}
