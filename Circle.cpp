#include "Circle.h"
Circle::Circle(float x, float y, float r) {
	radius = r;

}
std::string Circle::toString() {
	return std::to_string(area);
}