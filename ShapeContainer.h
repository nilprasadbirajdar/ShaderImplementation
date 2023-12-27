#pragma once
#include "Shape.h"


class ShapeContainer
{
public:
	ShapeContainer();
	~ShapeContainer();
public:
	std::vector<Line>& inLines();
	std::vector<Line>& clipedLines();

private:
	std::vector<Line> inputLines;
	std::vector<Line> mClipedLines;
	QVector<GLfloat>  mVertices;

	Shape mWindow;

};



