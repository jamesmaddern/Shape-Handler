#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(float x, float y, float h, float w) {
	std::cout << "Rectangle Created" << std::endl;
	height = h;
	width = w;
	leftTop = Point(x, y);
	updateShape(width, height);
}
Rectangle::~Rectangle() {
	std::cout << "Rectangle Destroyed" << std::endl;
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

std::ostream& Rectangle::toString(std::ostream& out) {		
	out << "\t-----Rectangle-----\n"
		<< "Perimeter = \t" << perimeter
		<< "\nArea = \t\t\t" << area <<
		"\nPoints =";
	for (int i = 0; i < points.size(); i++) {
		Point p = *points.at(i);
		out << "\t\tPoint " << i + 1 << ": [" <<
			p.getX() << ", " << p.getY() << "]\n\t ";
	}
	out << "\n";
	return out;
}


