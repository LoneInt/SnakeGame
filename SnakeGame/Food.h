#include "Sprite.h"

#ifndef FOOD_H__
#define FOOD_H__

class Food : public Sprite
{
public:
	Food() {};
	void draw() override;
	void CorGenerate();
	const Sprite* getLocation();
	void SpawnFood();
private:
	Sprite food;
};

#endif