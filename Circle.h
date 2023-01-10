#pragma once
#include "Movable.h"
#include "Shape.h"
class Circle :
    public Shape, public Movable
{
private:
	const double pi = 3.14159265358979323846;
    float radius;
public:
	Circle(float x, float y, float r);
	void calculateArea(float,float);
	void calculatePerimeter(float,float);
	
	void move(int, int);
	void scale(float, float);
	std::ostream& toString(std::ostream& out);
	
};

