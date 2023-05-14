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
	int dir;  //�����ߵ��Ƅӷ���
	void Increase();		//�ӳ�����
	bool Collision(const Sprite* temp);  //�ж����Ƿ�Ե�ʳ��
	void EdgeDetermine();
	void IntersectDet();
private:
	vector<Sprite> node;
};


#endif