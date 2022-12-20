#include "Square.h"

Square::Square(float x, float y, float e) {
	edge = e;
}
std::string Square::toString() {
	return std::to_string(area);
}