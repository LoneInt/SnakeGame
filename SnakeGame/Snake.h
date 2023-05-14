#include "Sprite.h"
#include<vector>


#ifndef SNAKE_H__
#define SNAKE_H__
class Snake : public Sprite
{
public:
	Snake(){};
	void draw() override;
	void BodyMove();
	void SnakeCorGenerate();
	int dir;  //表明蛇的移動方向
	void Increase();		//延长蛇身
	bool Collision(const Sprite* temp);  //判断蛇是否吃到食物
	void EdgeDetermine();
	void IntersectDet();
private:
	vector<Sprite> node;
};


#endif