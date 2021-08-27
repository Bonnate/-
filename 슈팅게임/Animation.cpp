#include "framework.h"

Animation::Animation(string tag, string name, bool active, float px, float py) : GameObject(tag, name, active, px, py)
{
	this->index = 0;
	this->imageTimer = .0f;
	this->imageDelay = 0.1f; 
	this->id = 0;
}

Animation::~Animation()
{

}

void Animation::draw()
{
	//애니메이션 타이머 시간 측정//
	imageTimer += Time::deltaTime;

	float px = getPx();
	float py = getPy();

	Bitmap::drawBMP(px, py, &image[id][index]);
	if(imageTimer >= imageDelay)
	{
		imageTimer = .0f;

		++index;
		if (index >= image[id].size()) index = 0;
	}
}

void Animation::addImage(const char* filename, int x, int y, int width, int height, int clipid)
{
	//애니메이션 스프라이트 이미지 로드하기
	Image img;
	while(image.size() <= clipid)
		image.push_back(vector <Image>());

	Bitmap::readBMP("Asset/적기.bmp", x, y, width, height, &img);
	image[clipid].push_back(img);
}

void Animation::setClipId(int clipId)
{
	id = clipId;
}