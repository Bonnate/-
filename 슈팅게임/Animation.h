#pragma once

#include "GameObject.h"
#include "BMP.h"
#include <vector>
using namespace std;

class Animation : public GameObject
{
private:
	//�̹��� ���� �迭//
	vector<vector<Image>> image;		//�̹����� �ִ� ���͸� ��Ƶδ� ����
	int		index;	//id ���� ���° �ִϸ��̼� �̹����� �����ٰ��ΰ�
	int		id;		//���¿� ���� id �ִϸ��̼� Ŭ��

	//�̹��� Ÿ�̸�(�ִϸ��̼� �ӵ� ������)//
	float imageTimer;
	float imageDelay;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void draw();

	void addImage(const char* filename, int x, int y, int width, int height, int clipid);
	void setClipId(int clipId);
};