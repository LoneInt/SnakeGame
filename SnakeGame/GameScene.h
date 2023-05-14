#include "Snake.h"
#include "Sprite.h"
#include "Food.h"

extern bool DeathDet;
#ifndef GAMESCENE_H__
#define GAMESCENE_H__

class GameScene
{
public:
	GameScene();
	void run();
	void onMsg(const ExMessage& msg);  //获取按键信息 by _getch
	void SnakeEat();
	void InitializeFS();
	void EdgeDetermination();
	void IntersectDet();
	void Death();
private:
	Snake snake;
	Food food;
};

#endif