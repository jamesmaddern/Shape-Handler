#pragma once
class Point
{
private:
	float _x;
	float _y;
public:
	Point() {
		_x = 0;
		_y = 0;
	};
	Point(int x, int y) {
		_x = x;
		_y = y;
	};
	int getX();
	int getY();
};

