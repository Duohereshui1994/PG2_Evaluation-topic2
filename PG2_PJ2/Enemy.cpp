#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include <Novice.h>
Enemy::Enemy()
{
	pos_ = { 1400.0f ,float(rand() % 656 )};
	velocity_ = { 10.0f,10.0f };
	width = 64.0f;
	height = 64.0f;
	isAlive_ = false;
	respawnTimer = 120+ rand() % 120;
}
void Enemy::Initalize()
{
	pos_ = { 1400.0f ,float(rand() % 656) };
	isAlive_ = false;
	respawnTimer = 120 + rand() % 120;
}
void Enemy::Update()
{
	if (!isAlive_)
	{
		if (respawnTimer > 0)
		{
			respawnTimer--;
		}
		else
		{
			pos_.x = 1400.0f;
			pos_.y = float(rand() % 656);
			respawnTimer = 180;
			isAlive_ = true;
		}
	}
	else
	{
		pos_.x -= velocity_.x;
		pos_.y += velocity_.y;
		if (pos_.y <= 0 || pos_.y >= 656)
		{
			velocity_.y *= -1;
		}
		if (pos_.x < -64.0f)
		{
			isAlive_ = false;
		}
	}
}
void Enemy::Draw()
{
	int Texture_Enemy = Novice::LoadTexture("./RS/enemy.png");
	if(isAlive_)
	{
		Novice::DrawSprite((int)pos_.x, (int)pos_.y, Texture_Enemy, 1, 1, 0.0f, WHITE);
	}
}
void Enemy::setIsAlive(bool isAlive)
{
	this->isAlive_ = isAlive;
}