#include "Scene.h"
#include <Novice.h>
Scene::Scene()
{
	scene = Title;
}
void Scene::Initalize()
{
	scene = Title;
}
void Scene::Update(char* keys, char* preKeys,Player obj)
{
	switch (scene)
	{
		case Title:
			if (keys[DIK_SPACE]&&!preKeys[DIK_SPACE])
			{
				scene = Game;
			}
			break;
		case Game:
			if (obj.getHp() <= 0)
			{
				scene = Lose;
			}
			if (obj.getScore() >=20)
			{
				scene = Win;
			}
			break;
		case Win:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
			{
				Initalize();
			}
			break;
		case Lose:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
			{
				Initalize();
			}
			break;
	}
}
void Scene::Draw()
{
	int Texture_Title = Novice::LoadTexture("./RS/title.png");
	int Texture_BG = Novice::LoadTexture("./RS/bg.png");
	int Texture_Win = Novice::LoadTexture("./RS/win.png");
	int Texture_Lose = Novice::LoadTexture("./RS/lose.png");
	switch (scene)
	{
		case Title:
			Novice::DrawSprite(0, 0, Texture_Title, 1, 1, 0.0f, WHITE);
			break;
		case Game:
			Novice::DrawSprite(0, 0, Texture_BG, 1, 1, 0.0f, WHITE);
			break;
		case Win:
			Novice::DrawSprite(0, 0, Texture_Win, 1, 1, 0.0f, WHITE);
			break;
		case Lose:
			Novice::DrawSprite(0, 0, Texture_Lose, 1, 1, 0.0f, WHITE);
			break;
	}
}