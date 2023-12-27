#pragma once
#include "Line.h"
#include <vector>
#include "pch.h"

using namespace std;

class SIMPLEDDA_API SimpleDDA
{
public:
	SimpleDDA();
	~SimpleDDA();

public:
	void drawGrid(vector<float>& vertices, vector<float>& colors);
	void drawLineBySimpleDDA(Line& line, vector<float>& mVertices);

public:
	vector<float> mVertices;
	vector<float> mColors;
};




