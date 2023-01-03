#include "Square.h"

Square::Square(float x, float y, float e) {
	edge = e;
	leftTop = Point(x, y);
	calculateArea(e, e);
	calculatePerimeter(e, e);
	calculatePoints(e, e);
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

	str += "Perimeter = " + std::to_string(perimeter) +
		"\nArea = " + std::to_string(area) +
		"\nPoints = ";
	for (int i = 0; i < points.size(); i++) {
		Point p = *points.at(i);

		str += "Point " + std::to_string(i + 1) + ": " +
			std::to_string(p.getX()) + ", " + std::to_string(p.getY()) + " ";
	}
	str += "\n";


	return str;
}