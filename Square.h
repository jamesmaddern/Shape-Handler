#pragma once
#include "Shape.h"
#include "Movable.h"
class Square :
    public Shape, public Movable
{
private:
    float edge;
public:
	Square(float x, float y, float e);
	
	void move(int, int);
	void scale(float,float);
	std::string toString();
};

