#include "pch.h"
#include "SutherlandCohen.h"

#include <vector>

using namespace std;

SutherlandCohen::SutherlandCohen(Line& line, Line& diagonalLine, vector<float>& mVertices, vector<float>& mColors)
{
    lineDrawingBySutherlandCohen(line, diagonalLine, mVertices, mColors);
}

SutherlandCohen::~SutherlandCohen()
{

}

//Compute Binary Code
int SutherlandCohen::computeBinaryCode(double x, double y, Line& diagonalLine)
{
    int code = INSIDE;
    if (x < diagonalLine.start().x())
    {
        code |= LEFT;
    }
    else if (x > diagonalLine.end().x())
    {
        code |= RIGHT;
    }

    if (y < diagonalLine.start().y())
    {
        code |= BOTTOM;
    }
    else if (y > diagonalLine.end().y())
    {
        code |= TOP;
    }
    return code;
}

//Sutherland cohen line cliping implimentation
void SutherlandCohen::lineDrawingBySutherlandCohen(Line& line, Line& diagonalLine, vector<float>& mVertices, vector<float>& mColors)
{

    mVertices.push_back(line.start().x());
    mVertices.push_back(line.start().y());

    mVertices.push_back(line.end().x());
    mVertices.push_back(line.end().y());

    mColors.push_back(1.0f);
    mColors.push_back(1.0f);
    mColors.push_back(0.0f);
    mColors.push_back(1.0f);
    mColors.push_back(1.0f);
    mColors.push_back(0.0f);

    int code1 = computeBinaryCode(line.start().x(), line.start().y(), diagonalLine);
    int code2 = computeBinaryCode(line.end().x(), line.end().y(), diagonalLine);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else {
            int code_out;
            double x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP)
            {
                x = line.start().x() + (line.end().x() - line.start().x()) * (diagonalLine.end().y() - line.start().y()) / (line.end().y() - line.start().y());
                y = diagonalLine.end().y();
            }
            else if (code_out & BOTTOM)
            {
                x = line.start().x() + (line.end().x() - line.start().x()) * (diagonalLine.start().y() - line.start().y()) / (line.end().y() - line.start().y());
                y = diagonalLine.start().y();
            }
            else if (code_out & RIGHT)
            {
                y = line.start().y() + (line.end().y() - line.start().y()) * (diagonalLine.end().x() - line.start().x()) / (line.end().x() - line.start().x());
                x = diagonalLine.end().x();
            }
            else if (code_out & LEFT)
            {
                y = line.start().y() + (line.end().y() - line.start().y()) * (diagonalLine.start().x() - line.start().x()) / (line.end().x() - line.start().x());
                x = diagonalLine.start().x();
            }
            if (code_out == code1)
            {
                line.start().setX(x);
                line.start().setY(y);
                code1 = computeBinaryCode(line.start().x(), line.start().y(), diagonalLine);
            }
            else {
                line.end().setX(x);
                line.end().setY(y);
                code2 = computeBinaryCode(line.end().x(), line.end().y(), diagonalLine);
            }
        }

    }
    if (accept)
    {
        mVertices.push_back(line.start().x());
        mVertices.push_back(line.start().y());

        mVertices.push_back(line.end().x());
        mVertices.push_back(line.end().y());

        mColors.push_back(150.0f);
        mColors.push_back(0.0f);
        mColors.push_back(0.0f);
        mColors.push_back(150.0f);
        mColors.push_back(0.0f);
        mColors.push_back(0.0f);
    }

}


