#include "Shape.h"
Shape::Shape(){
	isCircular = false;
};

void Shape::calculateArea(int width,int height) {
	area = width * height;
}
void Shape::calculatePerimeter(int width,int height) {
	perimeter = (width + height) * 2;
}
void Shape::calculatePoints(int width,int height) {
	Point* p1, * p2, * p3;

	points.push_back(&leftTop);
	if (!this->isCircular) { 
		p1 = new Point((leftTop.getX() + width), leftTop.getY());
		points.push_back(p1);
	}
	p2 = new Point((leftTop.getX() + width), (leftTop.getY() + height));
	points.push_back(p2);
	if (!this->isCircular) { 
		p3 = new Point(leftTop.getX(), (leftTop.getY() + height)); 
		points.push_back(p3);
	}

}