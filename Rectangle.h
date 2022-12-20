#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
private:
    float height;
    float width;
public:
	Rectangle(float x, float y, float h, float w);
	float calculateArea();
	float calculatePerimeter();
	float calculatePoints(Point* lt);
	void move();
	void scale();
	std::string toString();
};

