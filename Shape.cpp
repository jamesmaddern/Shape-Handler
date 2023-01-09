#include "Shape.h"
#include <iostream>
Shape::Shape(){
	isCircular = false;
	
};
Shape::~Shape() {
	
}
void Shape::updateShape(float w,float h) {
	this->calculateArea(w,h);
	this->calculatePerimeter(w,h);
	this->calculatePoints(w, h);
}
void Shape::calculateArea(float width,float height) {
	area = width * height;
}
void Shape::calculatePerimeter(float width,float height) {
	perimeter = (width + height) * 2;
}
void Shape::calculatePoints(float width,float height) {
	
	points.clear();
	
	Point* p1 = nullptr, * p2, * p3;
	
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
std::ostream& operator<<(std::ostream& out, Shape& obj) {
	return obj.toString(out);	
}