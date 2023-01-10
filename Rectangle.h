#pragma once
#include "Shape.h"
#include "Movable.h"
#include <iostream>
class Rectangle :
    public Shape, public Movable
{
private:
    float height;
    float width;
public:
    void move(int x, int y);
    void scale(float,float);   
	Rectangle(float x, float y, float h, float w);	
    ~Rectangle();
    std::ostream& toString(std::ostream&);     
};

