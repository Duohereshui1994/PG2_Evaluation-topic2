#pragma once
#include "Character.h"
class Enemy : public Character
{
public:
	Enemy();
	void Initalize();
	void Update();
	void Draw();
	Vector2 getPos()
	{
		Vector2 result;
		result.x = pos_.x;
		result.y = pos_.y;
		return result;
	}
	float getWidth()
	{
		return width;
	}
	float getHeight()
	{
		return height;
	}	
	bool getIsAlive()
	{
		return isAlive_;
	}
	void setIsAlive(bool isAlive);
private:
	int respawnTimer;
};

