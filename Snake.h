#include <raylib.h>
#include <deque>

class Snake
{
    private: 
        float cellSize{};
        int size{3};
        Vector2 direction{1, 0};
        float updateTime{0.16};
        float runningTime{};
    public:
        std::deque<Vector2> body{Vector2{4, 9}, Vector2{5, 9}, Vector2{6, 9}};
        void Draw();
        Snake(float cellSize);
        Rectangle getCollisionRec(int i);
        void Movement();
        void addSize();
        void Update(float deltaTime);
        int getSize()
        {
            return size;
        }
};