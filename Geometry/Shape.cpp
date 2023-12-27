#include "pch.h"
#include "Shape.h"

Shape::Shape()
{

}

Shape::Shape(Point3D inMin, Point3D inMax)
{
	Point3D p1 = inMin;
	Point3D p2 = Point3D(inMax.x(), inMin.y());
	Point3D p3 = inMax;
	Point3D p4 = Point3D(inMin.x(), inMax.y());

	Line l1 = Line(p1, p2);
	Line l2 = Line(p2, p3);
	Line l3 = Line(p3, p4);
	Line l4 = Line(p4, p1);

	mLines.push_back(l1);
	mLines.push_back(l2);
	mLines.push_back(l3);
	mLines.push_back(l4);
}

Shape::~Shape()
{

}

std::vector<Line> Shape::lines()
{
	return mLines;
}