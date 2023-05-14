#include<iostream>
#include<easyx.h>
#include "Sprite.h"
#include "Snake.h"
#include "GameScene.h"
#include "Food.h"
using namespace std;

extern bool DeathDet;
int main()
{
	initgraph(890, 640);
	Sleep(2000);
	srand(time(nullptr));
	GameScene scene;
	scene.InitializeFS();
	while (1)
	{
		scene.run();
		Sleep(100);
	};
	closegraph();
	//getchar();
	return 0;
}