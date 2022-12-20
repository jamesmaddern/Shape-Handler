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
	float calculateArea();
	float calculatePerimeter();
	float calculatePoints();
	std::string toString();
};

