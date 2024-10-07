#include <raylib.h>
#include "Food.h"

Food::Food(float cellSize) : 
    width(cellSize),
    height(cellSize),
    cellSize(cellSize)
{

}

void Food::setScreenPos(float x, float y)
{
    screenPos.x = x;
    screenPos.y = y;
}

void Food::Draw()
{
    Rectangle rec{screenPos.x * cellSize, screenPos.y * cellSize, width, height};
    DrawRectangleRounded(rec, 0.6, 1, RED);
}

Rectangle Food::getCollisionRec()
{
    return Rectangle{screenPos.x * cellSize, screenPos.y * cellSize, width, height}; 
}

