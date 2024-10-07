#include <raylib.h>
#include "Snake.h"
#include "Food.h"
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    const int cellSize{30};
    const int cells{25};

    Food food{(float)cellSize};

    Snake snake{(float)cellSize};

    food.setScreenPos((float)(rand()%25), float(rand()%25));

    InitWindow(cells*cellSize, cells*cellSize, "Snake");

    bool selfEating{};

    SetTargetFPS(60);
    while(!WindowShouldClose())   
    {
        const float dT{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        if(CheckCollisionRecs(snake.getCollisionRec(0), food.getCollisionRec()))
        {
            snake.addSize();
            food.setScreenPos((float)(rand()%25), float(rand()%25));
        }

        if(snake.body[0].x >= cells ||
           snake.body[0].y <= 0 ||
           snake.body[0].x <= 0 ||
           snake.body[0].y >= cells)
        {
            DrawText("GAME OVER", 225, 315, 50, BLUE);
            EndDrawing();
            continue;
        }

        for(int i = 3; i < snake.getSize(); i++)
        {
            if(CheckCollisionRecs(snake.getCollisionRec(i), snake.getCollisionRec(0)))
            {
                selfEating = 1;
            }
        }
        
        if(selfEating)
        {
            DrawText("GAME OVER", 225, 315, 50, BLUE);
            EndDrawing();
            continue;
        }

        snake.Movement();

        snake.Update(dT);

        snake.Draw();

        food.Draw();

        EndDrawing();
    }
    CloseWindow();
}