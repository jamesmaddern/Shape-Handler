#pragma once
class Point
{
private:
	int _x;
	int _y;
public:
	Point() {};
	Point(int x, int y) {
		_x = x;
		_y = y;
	};
	int getX();
	int getY();
	void setX(int);
	void setY(int);
};

