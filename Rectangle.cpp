#include "Rectangle.h"
#include <iostream>
Rectangle::Rectangle(float x, float y, float h, float w) {
	height = h;
	width = w;
	leftTop = Point(x, y);
	updateShape(width, height);
}


void Rectangle::move(int x, int y) {
	leftTop = Point(x, y);
	updateShape(width,height);
}
void Rectangle::scale(float scaleX, float scaleY) {
	width = width * scaleX;
	height = height * scaleY;
	updateShape(width, height);
}

std::string Rectangle::toString() {
	
	std::string str;
	str += "\t-----Rectangle-----\n";
	str += "Perimeter = \t" + std::to_string(perimeter) +
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
void Rectangle::Print() const {
	std::cout << "test" << std::endl;
}
