#pragma once
#include "Character.h"
#include "Bullet.h"
class Player : public Character
{
public:
	Player();
	Bullet bullet[10];
	void Initalize();
	void Update(char* keys);
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
	float getHp()
	{
		return hp_;
	}
	void setHp(float hp);
	float getHpMax()
	{
		return hpMax_;
	}
	bool getIsAlive()
	{
		return isAlive_;
	}
	void setIsAlive(bool isAlive);
	int getScore()
	{
		return score_;
	}
	void setScore(int score);
private:
	float hpMax_;
	float hp_;
	int CD;
	int score_;
};

