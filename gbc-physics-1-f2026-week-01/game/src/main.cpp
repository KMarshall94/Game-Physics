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

        DrawText(TextFormat("Launch Angle %2.1f", launch_angle), 10, 10, 20, DARKGRAY);
        DrawText(TextFormat("Launch Speed %2.1f", launch_speed), 10, 140, 20, DARKGRAY);
        DrawText(TextFormat("Launch Position X %2.1f", launch_speed), 10, 260, 20, DARKGRAY);
        DrawText(TextFormat("Launch Position Y %2.1f", launch_speed), 10, 380, 20, DARKGRAY);

        GuiSlider({ 10.0f, 50.0f, 160.0f, 80.0f }, "0", "90", &launch_angle, 0.0f, 90.0f);
        GuiSlider({ 10.0f, 170.0f, 160.0f, 80.0f }, "10", "300", &launch_speed, 10.0f, 300.0f);
        GuiSlider({ 10.0f, 290.0f, 160.0f, 80.0f }, "0", "800", &launch_position.x, 0.0f, GetScreenWidth());
        GuiSlider({ 10.0f, 410.0f, 160.0f, 80.0f }, "0", "800", &launch_position.y, 0.0f, GetScreenHeight());

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}