#include "stdafx.h"
#include "Point2D.h"
#include <iostream>
#include <cmath>



Point2D::Point2D(float x,float y):m_x(x),m_y(y)
{
}


Point2D::~Point2D()
{
}

void Point2D::Print()
{
	std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
}

float Point2D::distanceTo(const Point2D & point)
{
	return sqrtf((this->m_x- point.m_x)*(this->m_x - point.m_x)+ (this->m_y - point.m_y)*(this->m_y - point.m_y));
}

