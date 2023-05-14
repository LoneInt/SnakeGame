#include<easyx.h>
#include<iostream>
#include<ctime>
using namespace std;

#ifndef SPRITE_H__
#define SPRITE_H__
class Sprite
{
public:
		Sprite();
		Sprite(int x,int y);
		virtual void draw();
		void MoveBy(int dx, int dy);
		bool Collision(const Sprite* temp);
		void CoordinateGen();
		void SpawnFood();
		double PointDistance(const Sprite* item,const Sprite* temp);
protected:
		int cor_x;
		int cor_y;
		COLORREF color;  //the color of the object
};

#endif