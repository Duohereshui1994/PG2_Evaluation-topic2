#pragma once
#include "Player.h"
#include "enemy.h"
class Scene
{
public:
	Scene();
	void Initalize();
	void Update(char* keys, char* preKeys, Player obj);
	void Draw();
	int getSceneNum()
	{
		return scene;
	}
private:
	typedef enum
	{
		Title,
		Game,
		Win,
		Lose
	}SceneSet;
	SceneSet scene;
};

