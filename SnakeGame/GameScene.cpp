#include "GameScene.h"
#include "conio.h"
#include "Snake.h"
extern bool DeathDet;

GameScene::GameScene()
{
}

void GameScene::InitializeFS()		//初始化food和snake的位置
{
	food.CorGenerate();
	snake.SnakeCorGenerate();
}


void GameScene::onMsg(const ExMessage& msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		if(	msg.vkcode == VK_UP ||
			msg.vkcode == VK_DOWN || 
			msg.vkcode == VK_LEFT || 
			msg.vkcode == VK_RIGHT)
			switch (msg.vkcode)
			{
			case VK_UP:
				if(snake.dir != VK_DOWN) snake.dir = msg.vkcode;
				break;
			case VK_LEFT:
				if (snake.dir != VK_RIGHT) snake.dir = msg.vkcode;
				break;
			case VK_DOWN:
				if (snake.dir != VK_UP) snake.dir = msg.vkcode;
				break;
			case VK_RIGHT:
				if (snake.dir != VK_LEFT) snake.dir = msg.vkcode;
				break;
			}


	}
}

void GameScene::SnakeEat()
{
	if (snake.Collision(food.getLocation()))		//
	{
		snake.Increase();
		food.SpawnFood();
	}
}

void GameScene::run()
{

	BeginBatchDraw(); //双缓冲绘图
	cleardevice();  //清屏 防止色块残留
	food.draw();
	snake.draw();
	EndBatchDraw();  //結束雙緩衝繪圖
	snake.BodyMove();
	SnakeEat();   //判斷蛇是否吃到食物
	ExMessage msg{ 0 };
	while (peekmessage(&msg, 2))
	{
		onMsg(msg);
	}
	Death();
}

void GameScene::EdgeDetermination()
{
	snake.EdgeDetermine();
}

void GameScene::IntersectDet()
{
	snake.IntersectDet();
}

void GameScene::Death()
{
	if (DeathDet) closegraph();
}