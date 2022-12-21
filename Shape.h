#pragma once
#include <vector>
#include "Point.h"
#include <string>
class Shape
{
protected:
	float area;
	bool isCircular;
	Point leftTop;
	float perimeter;
	std::vector<Point*> points;
public:
	Shape();
	void calculateArea(int, int);
	void calculatePerimeter(int, int);
	void calculatePoints(int, int);
	std::string toString();
};

