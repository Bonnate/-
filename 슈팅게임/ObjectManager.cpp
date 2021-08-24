#include "framework.h"

vector<GameObject*> ObjectManager::gameObject;

void ObjectManager::instantiate(GameObject* o)
{
	gameObject.push_back(o);
	o->start();
}

void ObjectManager::destroy(GameObject* o)
{
	for (int i = 0; i < gameObject.size(); i++)
	{
		if (gameObject[i] == o)
		{
			delete gameObject[i];					 //객체 삭제
			gameObject.erase(gameObject.begin() + i);//stl vector의 주소 저장 공간 삭제

			break; //삭제후..반복문 종료
		}
	}
}

void ObjectManager::update()
{
	for (int i = 0; i < gameObject.size(); i++)
	{
		gameObject[i]->update();
	}
}

void ObjectManager::draw()
{
	for (int i = 0; i < gameObject.size(); i++)
	{
		if (gameObject[i]->getActive() == true)
		{
			gameObject[i]->draw();
		}
	}
}

void ObjectManager::clear()
{
	for (int i = 0; i < gameObject.size(); i++)
	{
		delete gameObject[i];
	}

	gameObject.clear();
}