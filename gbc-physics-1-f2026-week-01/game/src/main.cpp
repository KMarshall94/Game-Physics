#include "raylib.h"
#include "raymath.h"
#include "raygui.h"
#include "cstdio"
int main()
{
    InitWindow(800, 800, "Physics-1");
    InitAudioDevice();
    SetTargetFPS(60);
    /*Set Vector2 for launch position
      Set Floats for Launch angle and speed*/

    /*
    Need to negate launch angle so it points upwards, Raylib is RHS
    */
    while (!WindowShouldClose())
    {
        // 1. Calculate launch_direction Vector2 by using the Vector2Rotate function.
       // (Be sure to convert launch_angle from degrees to radians when passing it to Vector2Rotate)!
       // 2. Calculate launch_velocity Vector2 by multiplying launch_direction by launch_speed
       // 3. Render launch_velocity as a line from launch_position to launch_position + launch_velocity

        BeginDrawing();
            ClearBackground(WHITE);

            // Draw your launch_position + launch_velocity line here!

            DrawCircleV(GetMousePosition(), 20.0f, RED);


        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
