#include "framework.h"


GameBG::GameBG(string tag, string name, bool active, float px, float py):Sprite(tag, name, active, px, py)
{

}

GameBG::GameBG() : Sprite("", "", true, 0, 0)
{

}

GameBG::~GameBG()
{

}

void GameBG::start()
{
	//��������Ʈ �̹��� �ε�//
	setImage("Asset/���ӹ��.bmp");
}

void GameBG::update()
{
	
}
