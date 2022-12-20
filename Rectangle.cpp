#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float h, float w) {
	height = h;
	width = w;
	Point lT(x, y);
	calculateArea();
	calculatePerimeter();
	calculatePoints(&lT);
}


float Rectangle::calculateArea() {
	area = width * height;

	return 0;
}
float Rectangle::calculatePerimeter() {
	perimeter = (width + height) * 2;
	return 0;
}
float Rectangle::calculatePoints(Point* p0) {
	Point* p1,* p2,* p3;
	Point temp;
	points.push_back(p0);
	temp = *p0;
	p1 = new Point((temp.getX() + width), temp.getY());
	p2 = new Point((temp.getX() + width), (temp.getY() - height));
	p3 = new Point(temp.getX(), (temp.getY() - height));

	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	
	return 0;
}

std::string Rectangle::toString() {
	std::string str;

	str += "Perimeter = " + std::to_string(perimeter) + 
		"\nArea = " + std::to_string(area) + 
		"\nPoints = ";
	for (int i = 0; i < points.size(); i++) {
		Point p = *points.at(i);
		
		str += "Point " + std::to_string(i+1) + ": " + 
			std::to_string(p.getX()) + ", " + std::to_string(p.getY()) + " ";
	}
	str += "\n";


	return str;
}