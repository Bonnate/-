#pragma once

#include <vector>
#include "GameObject.h"

class ObjectManager
{
private:
	static vector<GameObject*> gameObject[10];		//0,1,2... ���̾� ����.. ���� �������� �Ʒ��� ��

public:

	//stl vector�� �ν���Ʈ(��ü) �߰�/���� �Լ�//
	static void instantiate(GameObject* o, int layer);
	static void destroy(GameObject* o);

	//��Ͽ�..�߰��� ��ü..������Ʈ �Լ�//
	static void update();

	//���ü..�߰��� ��ü..�׸��� �Լ�//
	static void draw();

	//��Ͽ�..�߰��� ��ü..��� ���� �Լ�//
	static void clear();
};