#include "Circle.h"
Circle::Circle(float x, float y, float r) {
	radius = r;
	leftTop = Point(x, y);
	isCircular = true;
	updateShape(radius*2,radius*2);
	

}

void Circle::calculateArea(float w, float h) {
	area = pi * radius * radius;
}
void Circle::calculatePerimeter(float w, float h)
{
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
std::string Circle::toString() {
	std::string str;
	str += "\t-----CIRCLE-----\n";
	str += "Circumference = \t" + std::to_string(perimeter) +
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