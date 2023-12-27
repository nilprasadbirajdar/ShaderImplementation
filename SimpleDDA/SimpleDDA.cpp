#include "pch.h"
#include "SimpleDDA.h"

SimpleDDA::SimpleDDA()
{

}

SimpleDDA::~SimpleDDA()
{

}


//Code to draw a grid
void SimpleDDA::drawGrid(vector<float>& vertices, vector<float>& colors)
{
    const float gridSize = 50.0f;
    const float step = 1.0f;

    // Code to draw horizontal lines
    for (float y = -gridSize / 2.0f; y <= gridSize / 2.0f; y += step)
    {
        vertices.push_back(-gridSize / 2.0f);
        vertices.push_back(y);

        vertices.push_back(gridSize / 2.0f);
        vertices.push_back(y);

        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
    }

    // Code to draw Vertical lines
    for (float x = -gridSize / 2.0f; x <= gridSize / 2.0f; x += step)
    {
        vertices.push_back(x);
        vertices.push_back(-gridSize / 2.0f);

        vertices.push_back(x);
        vertices.push_back(gridSize / 2.0f);


        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
        colors.push_back(1.0f);
    }
}

//Symmetric DDA implimentation
void SimpleDDA::drawLineBySimpleDDA(Line& line, vector<float>& mVertices)
{
    float dx = abs(line.end().x() - line.start().x());
    float dy = abs(line.end().y() - line.start().y());
    float deltaX;
    float deltaY;
    if (dy > dx)
    {
        deltaX = dx / dy;
        deltaY = dy / dy;
    }
    else
    {
        deltaX = dx / dx;
        deltaY = dy / dx;
    }
    while (line.start().x() < line.end().x())
    {

        line.start().setX(deltaX + line.start().x());
        line.start().setY(deltaY + line.start().y());
    }


}



