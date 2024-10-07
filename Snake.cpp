#include <raylib.h>
#include <raymath.h>
#include <deque>
#include "Snake.h"

Snake::Snake(float cellSize) :
    cellSize(cellSize)
{

}

void Snake::Draw()
{
    for(auto bod : body)
    {
        Rectangle rec{bod.x * cellSize, bod.y * cellSize, cellSize, cellSize};
        DrawRectangleRounded(rec, 0.2, size, BLACK);
        DrawRectangleLines(getCollisionRec(0).x, getCollisionRec(0).y, getCollisionRec(0).width, getCollisionRec(0).height, RED);
    }
}

void Snake::Movement()
{
    if(direction.y != 1)
    {
        if(IsKeyPressed(KEY_W))
        {
            direction = {0, -1};
        }
    }
    if(direction.y != -1)
    {
        if(IsKeyPressed(KEY_S))
        {
            direction = {0, 1};
        }
    }
    if(direction.x != 1)
    {
        if(IsKeyPressed(KEY_A))
        {
            direction = {-1, 0};
        }
    }
    if(direction.x != -1)
    {
        if(IsKeyPressed(KEY_D))
        {
            direction = {1, 0};
        }
    }
}

void Snake::addSize()
{
    body.push_back(Vector2Add(body[size-1], direction));
    size += 1;
}

void Snake::Update(float deltaTime)
{
    runningTime += deltaTime;
    if(runningTime >= updateTime)
    {
        runningTime = 0;
        body.pop_back();
        body.push_front(Vector2Add(direction, body[0]));
    }
}

Rectangle Snake::getCollisionRec(int i)
{
    return Rectangle{body[i].x * cellSize + cellSize/4, body[i].y * cellSize + cellSize/4, cellSize/2, cellSize/2};
}
