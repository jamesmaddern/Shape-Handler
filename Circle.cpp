#include "Circle.h"
Circle::Circle(float x, float y, float r) {
	radius = r;
	leftTop = Point(x, y);
	isCircular = true;
	calculateArea();
	calculatePerimeter();
	calculatePoints(radius * 2, r * 2);

}

void Circle::calculateArea() {
	area = pi * radius * radius;
}
void Circle::calculatePerimeter()
{
	perimeter = 2 * pi * radius;
}

std::string Circle::toString() {
	std::string str;

	str += "Circumference = " + std::to_string(perimeter) +
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