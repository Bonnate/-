#include "framework.h"

Player::Player() : GameObject("", "", true, 0, 0)
{
	this->speed = 200.0f;;
	this->fireTimer = .0f;
	this->fireDelay = .2f;
	this->index = 3;
	this->changeImageDelay = .0f;
}

Player::Player(float px, float py) : GameObject("", "", true, px, py)
{
	this->speed = 200.0f;
	this->fireTimer = .0f;
	this->fireDelay = .2f;
	this->index = 3;
	this->changeImageDelay = .0f;
}

Player::~Player()
{
	for (int i = 0; i < 7; ++i)
		delete[] image[i].argb;
}

void Player::start()
{
	//플레이어 이미지들 ..로드하기//
	for (int i = 0; i < 7; ++i)
		Bitmap::readBMP("Asset/팬텀이동2.bmp", 64 * i, 82, 62, 80, &image[i]);

}

void Player::update()
{
	GetKeytoMove();
	GetKeytoShoot();
}

void Player::draw()
{
	//이미지 그리기//
	float px = getPx();
	float py = getPy();

	Bitmap::drawBMP(px, py, &image[index]);
}

void Player::GetKeytoMove()
{
	float dist = speed * Time::deltaTime;

	if (Input::getKeyDown("up") || Input::getKey("up"))
	{
		translate(0, -dist);

		if (getPy() < -3) setPy(-3);
	}

	if (Input::getKeyDown("down") || Input::getKey("down"))
	{
		translate(0, dist);

		if (getPy() > HEIGHT - 68) setPy(HEIGHT - 68);
	}

	if (Input::getKeyDown("left") || Input::getKey("left"))
	{
		changeImageDelay += Time::deltaTime;

		translate(-dist, 0);

		if (getPx() < -10) setPx(-10);

		if (changeImageDelay >= 0.1f)
		{
			index ? --index : index = 0;
			changeImageDelay = .0f;
		}
	}

	if (Input::getKeyDown("right") || Input::getKey("right"))
	{
		changeImageDelay += Time::deltaTime;

		translate(dist, 0);

		if (getPx() > WIDTH - 52) setPx(WIDTH - 52);

		if (changeImageDelay >= 0.1f)
		{
			index == 6 ? index = 6 : ++index;
			changeImageDelay = .0f;
		}
	}

	if (!Input::getKey("left") && !Input::getKey("right"))
	{
		changeImageDelay += Time::deltaTime;

		if (index == 3) { return; }
		else if (index < 3)
		{
			if (changeImageDelay >= 0.1f)
			{
				++index;
				changeImageDelay = .0f;
			}
		}
		else
		{
			if (changeImageDelay >= 0.1f)
			{
				--index;
				changeImageDelay = .0f;
			}
		}

	}
		
}

void Player::GetKeytoShoot()
{
		if (Input::getKey("space") || Input::getKeyDown("space"))
		{
			fireTimer += Time::deltaTime;

			if (fireTimer >= fireDelay)
			{
				instantiate(new PlayerLaser(getPx() + 28, getPy() - 20), 0);

				//instantiate(new PlayerLaser(getPx() + 21, getPy() - 20));
				//instantiate(new PlayerLaser(getPx() + 41, getPy() - 20));

				//instantiate(new PlayerLaser(getPx() + 21, getPy() - 20, -1));
				//instantiate(new PlayerLaser(getPx() + 31, getPy() - 20));
				//instantiate(new PlayerLaser(getPx() + 41, getPy() - 20, +1));

				fireTimer = .0f;
			}
		}
}