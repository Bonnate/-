#include "framework.h"

Player::Player() : Sprite("", "", true, 0, 0)
{
	this->speed = 200.0f;
	this->fireTimer = .0f;
	this->fireDelay = .2f;
}

Player::Player(float px, float py) : Sprite("", "", true, px, py)
{
	this->speed = 200.0f;
	this->fireTimer = .0f;
	this->fireDelay = .2f;
}

Player::~Player()
{

}

void Player::start()
{
	setImage("Asset/플레이어.bmp");
}

void Player::update()
{
	GetKeytoMove();
	
	fireTimer += Time::deltaTime;
	
	if(fireTimer >= fireDelay)
		if (Input::getKey("space") || Input::getKeyDown("space"))
		{
			instantiate(new PlayerLaser(getPx() + 32, getPy() - 20));

			fireTimer = .0f;
		}
}

void Player::GetKeytoMove()
{
	float dist = speed * Time::deltaTime;

	if (Input::getKeyDown("up") || Input::getKey("up"))
	{
		translate(0, -dist);

		if (getPy() < 0) setPy(0);
	}

	if (Input::getKeyDown("down") || Input::getKey("down"))
	{
		translate(0, dist);

		if (getPy() > HEIGHT - 68) setPy(HEIGHT - 68);
	}

	if (Input::getKeyDown("left") || Input::getKey("left"))
	{
		translate(-dist, 0);

		if (getPx() < 0) setPx(0);
	}

	if (Input::getKeyDown("right") || Input::getKey("right"))
	{
		translate(dist, 0);

		if (getPx() > WIDTH - 81) setPx(WIDTH - 81);
	}


}

void Player::GetKeytoShoot()
{

}