#pragma once
#include "Shape.h"
#include "Movable.h"
class Square :
    public Shape, public Movable
{
private:   
    float edge;
public:
	~Square();
	Square(float x, float y, float e);	
	void move(int x, int y);	
	void scale(float,float);
	std::ostream& toString(std::ostream&);
};

