#include "Square.h"
#include <math.h>
#include<iostream>
Square::Square(float x, float y, float e) {
	edge = e;
	leftTop = Point(x, y);
	calculateArea(e, e);
	calculatePerimeter(e, e);
	calculatePoints(e, e);
}
Square::~Square() {
	std::cout << "Square Deleted";
}
void Square::move(int x, int y) {
	leftTop = Point(x, y);
	updateShape(edge, edge);
}
void Square::scale(float scaleX, float scaleY) {
	edge = edge * scaleX;
	
	updateShape(edge, edge);
}


std::string Square::toString() {
	std::string str;
	float temp = roundf((perimeter * 100) / 100);
	str += "\t-----Square-----\n";
	str += "Perimeter = \t" + std::to_string(temp) +
		"\nArea = \t\t\t" + std::to_string(area) +
		"\nPoints =";
	for (int i = 0; i < points.size(); i++) {
		Point p = *points.at(i);

		str += "\t\tPoint " + std::to_string(i + 1) + ": [" +
			std::to_string(p.getX()) + ", " + std::to_string(p.getY()) + "]\n\t ";
	}
	str += "\n";


	return str;
}