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
	//스프라이트 이미지 로드//
	setImage("Asset/게임배경.bmp");
}

void GameBG::update()
{
	
}
