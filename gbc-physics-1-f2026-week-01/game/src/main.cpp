#include "raylib.h"
#include "raymath.h"
#include "raygui.h"
#include "cstdio"

int main()
{
    InitWindow(800, 800, "Physics-1");
    InitAudioDevice();
    SetTargetFPS(60);

    Vector2 launch_position = { 100.0f, 700.0f };
    float launch_angle = 0.0f;
    float launch_speed = 100.0f;

    while (!WindowShouldClose())
    {
        Vector2 launch_direction = Vector2Rotate(Vector2UnitX, -launch_angle * DEG2RAD);

        Vector2 launch_velocity = launch_direction * launch_speed;

        BeginDrawing();

        ClearBackground(WHITE);

        DrawCircleV(launch_position, 20.0f, GRAY);

        DrawLineEx(launch_position, launch_position + launch_velocity, 4.0f, ORANGE);

        DrawCircleV(GetMousePosition(), 20.0f, RED);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}