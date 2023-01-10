#pragma once
//pure virtual (abstract) class to indicate if a shape is movable
class Movable
{
public:
	virtual void move(int,int)=0;
	virtual void scale(float,float)=0;
};

