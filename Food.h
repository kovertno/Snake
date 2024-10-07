#include <raylib.h>

class Food
{
    private:    
        float width{};
        float height{};
        float cellSize{};
        Vector2 screenPos{};
    public:
        Food(float cellSize);
        void setScreenPos(float x, float y);
        void Draw();
        Rectangle getCollisionRec();
};