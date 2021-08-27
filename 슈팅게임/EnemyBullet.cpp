#include "framework.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("", "", true, px, py)
{
	this->speed = 100.0f;
}

EnemyBullet::~EnemyBullet()
{

}

void EnemyBullet::start()
{
	setImage("Asset/ÃÑ¾Ë1.bmp");
}

void EnemyBullet::update()
{
	translate(0, speed * Time::deltaTime);
}