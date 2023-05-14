#include "GameScene.h"
#include "conio.h"
#include "Snake.h"
extern bool DeathDet;

GameScene::GameScene()
{
}

void GameScene::InitializeFS()		//��ʼ��food��snake��λ��
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

	BeginBatchDraw(); //˫�����ͼ
	cleardevice();  //���� ��ֹɫ�����
	food.draw();
	snake.draw();
	EndBatchDraw();  //�Y���p���n�L�D
	snake.BodyMove();
	SnakeEat();   //�Д����Ƿ�Ե�ʳ��
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