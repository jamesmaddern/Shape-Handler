#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
private:
    float radius;
public:
	Circle(float x, float y, float r);
	float calculateArea();
	float calculatePerimeter();
	float calculatePoints();
	void move();
	void scale();
	std::string toString();
};

