#include "raylib.h"
#include "raymath.h"
#include "raygui.h"
#include "cstdio"
int main()
{
    InitWindow(800, 800, "Physics-1");
    InitAudioDevice();
    SetTargetFPS(60);

    float x = 400.0f;
    float y = 400.0f;
    float a = 10.0f;    // frequency (rate of movement)
    float b = 4.0f;    // amplitude (radius of movement)

    Vector2 pos = { 100.0f, 400.0f };

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        float t = GetTime();
        printf("%f\n", t);
        //TraceLog(LOG_INFO, "%f", time); // raylib uses tracelog to output to the console
        //TraceLog(LOG_INFO, "%f", dt);

        // Simple animation
        pos += Vector2UnitX * 100.0f * dt;

        //Animate x and y based on a and b floats
        y = y + (cos(t * a)) * a * b * dt;
        x = x + (-sin(t * a)) * a * b * dt;

        BeginDrawing();
            ClearBackground(WHITE);

            DrawCircleV(pos, 20.0f, RED);

            DrawCircle(50, 100, 25.0f, GREEN);
            DrawCircle(150, 200, 25.0f, DARKGREEN);
            DrawLine(50, 100, 150, 200, LIME);

            DrawCircleV(GetMousePosition(), 20.0f, RED);
            DrawText("Kirby Marshall 101554268", 540, 750, 20, ORANGE);
            // If you want to be very accurate with formatting, use the MeasureText function!
            //MeasureText("Connor Smiley 123456", 20);

            // Use TextFormat to convert data (like int or float) to const char* (text)!
            // TextFormat follows C-style formatting: https://cplusplus.com/reference/cstdio/printf/

            const char* text = TextFormat("Time: %.2f", t);
            //TODO -- make time 2 decimals
            DrawText(text, 650, 5, 20, BLUE);
            
            DrawCircle(x, y, 25.0f, PURPLE);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
