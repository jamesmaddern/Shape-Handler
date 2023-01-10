#include "Circle.h"
#include <iostream>
Circle::Circle(float x, float y, float r) {
	std::cout << "Circle Created" << std::endl;
	radius = r;
	leftTop = Point(x, y);
	isCircular = true;
	updateShape(radius*2,radius*2);
}
Circle::~Circle() {
	std::cout << "Circle Destroyed" << std::endl;
}

void Circle::calculateArea(float w, float h) {
	area = pi * radius * radius;
}
void Circle::calculatePerimeter(float w, float h){
	perimeter = 2 * pi * radius;
}
void Circle::move(int x, int y) {
	leftTop = Point(x, y);
	updateShape(radius*2, radius*2);
}
void Circle::scale(float scaleR, float) {
	radius = radius * scaleR;
	updateShape(radius*2, radius*2);
}
std::ostream& Circle::toString(std::ostream& out) {	
	out << "\t-----CIRCLE-----\n"
	<< "Circumference = \t" << perimeter <<
		"\nArea = \t\t\t" << area <<
		"\nPoints =";
	for (int i = 0; i < points.size(); i++) {
		Point p = *points.at(i);
		out << "\t\tPoint " << i + 1 << ": [" <<
			p.getX() << ", " << p.getY() << "]\n\t ";
	}
	out << "\n";
	return out;
}
