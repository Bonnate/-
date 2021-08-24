#pragma once

#include <string>

using namespace std;

class GameObject
{
private:
	string tag;
	string name;
	bool   active;

	float px, py;
public:
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	string getTag();
	string getName();
	bool   getActive();
	float  getPx();
	float  getPy();

	void setTag(string tag);
	void setName(string name);
	void setActive(bool active);
	void setPx(float px);
	void setPy(float py);

	virtual void start();
	virtual void update();
	virtual void draw();

	void translate(float x, float y);

	void instantiate(GameObject* o);
};