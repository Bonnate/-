#include "framework.h"

vector<GameObject*> ObjectManager::gameObject[10];

void ObjectManager::instantiate(GameObject* o, int layer)
{
	gameObject[layer].push_back(o);
	o->start();
}

void ObjectManager::destroy(GameObject* o)
{
	for(int j = 0; j < 10; ++j)
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			if (gameObject[j][i] == o)
			{
				delete gameObject[j][i];							//��ü ����
				gameObject[j].erase(gameObject[j].begin() + i);		//stl vector�� �ּ� ���� ���� ����

				return; //������..�ݺ��� ����
			}
		}
}

void ObjectManager::update()
{
	for (int j = 0; j < 10; ++j)
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			gameObject[j][i]->update();
		}
}

void ObjectManager::draw()
{
	for (int j = 0; j < 10; ++j)
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			if (gameObject[j][i]->getActive() == true)
			{
				gameObject[j][i]->draw();
			}
		}
}

void ObjectManager::clear()
{
	for (int j = 0; j < 10; ++j)
	{
		for (int i = 0; i < gameObject[j].size(); i++)
		{
			delete gameObject[j][i];
		}

		gameObject[j].clear();
	}
}