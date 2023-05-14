#include "Snake.h"
#include<conio.h>

bool DeathDet = false;  //"false" means you are alive while "true" means you are dead.
//Snake::Snake()
//{
//	dir = VK_RIGHT;  //初始化蛇头方向
//	node.push_back(Sprite(100,200));
//	node.push_back(Sprite(90,200));
//	node.push_back(Sprite(80,200));
//}
//
//Snake::Snake(int x, int y):Sprite(x,y)
//{
//	dir = VK_RIGHT;  //初始化蛇头方向
//	node.push_back(Sprite(100, 200));
//	node.push_back(Sprite(90, 200));
//	node.push_back(Sprite(80, 200));
//}


void Snake::draw()
{
	for (auto& x : node)
		x.draw();
}


void Snake::BodyMove()
{
	//auto ch = _getch();
	//dir = ch;
	for (int i = node.size() - 1; i > 0; i--)
	{
		node[i] = node[i - 1];
	}
	switch (dir)
	{
	case VK_UP:			//Move up 72
		node[0].MoveBy(0, -10);
		break;
	case VK_DOWN:			//Move down 80
		node[0].MoveBy(0, 10);
		break;
	case VK_LEFT:			//Move left 75
		node[0].MoveBy(-10, 0);
		break;
	case VK_RIGHT:			//Move right 77
		node[0].MoveBy(10, 0);
		break;
	}

}


void Snake::SnakeCorGenerate()
{
	dir = VK_RIGHT;   //初始化蛇头方向
	node.push_back(Sprite(120, 100));
	node.push_back(Sprite(110, 100));
	node.push_back(Sprite(100, 100));
	//蛇身初始有三节

}

void Snake::Increase()
{
	node.push_back(Sprite(0,0));
}

bool Snake::Collision(const Sprite* temp)
{
	if (PointDistance(&node[0],temp) <= 100.0)
		return true;
	else return false;
	//return node[0].Collision(temp);
}

void Snake::EdgeDetermine()
{
	if (cor_x == 0 || cor_x == 890 || cor_y == 640 || cor_y == 0)
	{
		DeathDet = true;
	}
}

void Snake::IntersectDet()
{
	for (int i=1;i<node.size();i++)
	{
		if (PointDistance(&node[0], &node[i]) < 100)
		{
			DeathDet = true;
			break;
		}
	}
}