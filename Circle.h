#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
private:
	const double pi = 3.14159265358979323846;
    float radius;
public:
	Circle(float x, float y, float r);
	void calculateArea();
	void calculatePerimeter();
	
	void move();
	void scale();
	std::string toString();
};

