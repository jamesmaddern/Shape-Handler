#include "Square.h"
#include <math.h>
#include<iostream>
#include <algorithm>

Square::Square(float x, float y, float e) {
	std::cout << "Square Created" << std::endl;
	edge = e;
	leftTop = Point(x, y);
	calculateArea(e, e);
	calculatePerimeter(e, e);
	calculatePoints(e, e);
}
Square::~Square() {
	std::cout << "Square Deleted" << std::endl;		
}

void Square::move(int x, int y) {
	leftTop = Point(x, y);
	updateShape(edge, edge);
}
void Square::scale(float scaleX, float scaleY) {
	edge = edge * scaleX;	
	updateShape(edge, edge);
}


std::ostream& Square::toString(std::ostream& out) {
	out << "\t-----Square-----\n"
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