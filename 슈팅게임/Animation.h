#pragma once

#include "GameObject.h"
#include "BMP.h"
#include <vector>
using namespace std;

class Animation : public GameObject
{
private:
	//이미지 저장 배열//
	vector<vector<Image>> image;		//이미지를 넣는 벡터를 담아두는 벡터
	int		index;	//id 내의 몇번째 애니메이션 이미지를 보여줄것인가
	int		id;		//상태에 따른 id 애니메이션 클립

	//이미지 타이머(애니메이션 속도 조절용)//
	float imageTimer;
	float imageDelay;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void draw();

	void addImage(const char* filename, int x, int y, int width, int height, int clipid);
	void setClipId(int clipId);
};