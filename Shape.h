#pragma once
#include <vector>
#include "Point.h"
#include <string>
#include <iostream>
class Shape
{
protected:	
	float area;
	bool isCircular;
	Point leftTop;
	float perimeter;
	std::vector<Point*> points;
public:
	virtual ~Shape();
	Shape();
	void updateShape(float,float);
	virtual void calculateArea(float, float);
	virtual void calculatePerimeter(float, float);
	void calculatePoints(float, float);
	virtual std::ostream& toString(std::ostream&) = 0;
	friend std::ostream& operator<<(std::ostream&, Shape& obj);
};

