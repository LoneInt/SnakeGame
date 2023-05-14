#include "Food.h"



void Food::CorGenerate()
{
	food.CoordinateGen();
}

void Food::draw()
{
	food.draw();
}

const Sprite* Food::getLocation()
{
	return &food;
}

void Food::SpawnFood()
{
	food.SpawnFood();
}