#pragma once
class Point2D
{
public:
	Point2D(float x=0,float y=0);
	~Point2D();
	void Print();
	float distanceTo(const Point2D &point);
	
private:
	float m_x = 0;
	float m_y = 0;
};

