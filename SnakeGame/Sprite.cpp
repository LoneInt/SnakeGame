#include "Sprite.h"
#include<math.h>

Sprite::Sprite()
{
	//cor_x = 100;
	//cor_y = 200;
	//color = RED;
}

Sprite::Sprite(int x, int y)
{
	cor_x = x;
	cor_y = y;
	color = RED;
}

void Sprite::draw()
{
	setfillcolor(color); // set the color of the rectangle
	//fillrectangle(cor_x, cor_y, cor_x + 10, cor_y + 10);

	fillcircle(cor_x, cor_y, 5);
}

void Sprite::CoordinateGen()
{
	cor_x = 200;
	cor_y = 100;
	color = YELLOW;
}

void Sprite::MoveBy(int dx, int dy)
{
	cor_x += dx;
	cor_y += dy;
}

bool Sprite::Collision(const Sprite* temp)
{
	return (cor_x == temp->cor_x && cor_y == temp->cor_y);
}

void Sprite::SpawnFood()
{
	cor_x = rand() % 89 + 10;
	cor_y = rand() % 64 + 10;
}

double Sprite::PointDistance(const Sprite* item,const Sprite* temp)
{
	double result;
	result = pow(((double)item->cor_x - (double)temp->cor_x), 2) + pow(((double)item->cor_y - (double)temp->cor_y), 2);
	return result;
}