#pragma once

#include <vector>
#include "GameObject.h"

class ObjectManager
{
private:
	static vector<GameObject*> gameObject[10];		//0,1,2... 레이어 개념.. 수가 작을수록 아래에 깔림

public:

	//stl vector에 인스턴트(객체) 추가/삭제 함수//
	static void instantiate(GameObject* o, int layer);
	static void destroy(GameObject* o);

	//목록에..추가된 객체..업데이트 함수//
	static void update();

	//목록체..추가된 객체..그리기 함수//
	static void draw();

	//목록에..추가된 객체..모두 제거 함수//
	static void clear();
};