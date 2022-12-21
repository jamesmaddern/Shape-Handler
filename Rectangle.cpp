#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float h, float w) {
	height = h;
	width = w;
	leftTop = Point(x, y);
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}


float Rectangle::calculateArea() {
	area = width * height;

	return 0;
}
float Rectangle::calculatePerimeter() {
	perimeter = (width + height) * 2;
	return 0;
}
float Rectangle::calculatePoints() {
	Point* p1,* p2,* p3;
	
	points.push_back(&leftTop);
	p1 = new Point((leftTop.getX() + width), leftTop.getY());
	p2 = new Point((leftTop.getX() + width), (leftTop.getY() + height));
	p3 = new Point(leftTop .getX(), (leftTop.getY() + height));

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