#pragma once
#include <iostream>
class Point
{
private:
	float _x;
	float _y;
public:
	~Point() {
		//std::cout << "Point Destroyed";
	}
	Point() {
		_x = 0;
		_y = 0;
	};
	Point(float x, float y) {
		_x = x;
		_y = y;
	};
	int getX();
	int getY();
};

