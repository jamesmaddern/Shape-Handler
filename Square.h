#pragma once
#include "Shape.h"
class Square :
    public Shape
{
private:
    float edge;
public:
	Square(float x, float y, float e);
	
	void move();
	void scale();
	std::string toString();
};

