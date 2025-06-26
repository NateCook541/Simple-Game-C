#include "raylib.h"
#include "config.h"
#include "screens.h"
#include "gameplay.h"
#include <iostream>

// Global variable declarations
int playerHealth = 3;
int daysPassed = 0;

void configureWindow() {
    InitWindow(screenWidth, screenHeight, "Game V3");
    SetTargetFPS(60);
} // End configureWindow

void startGame() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // Welcome
        welcomeScreen();
        enterStart();
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        } // End if
        EndDrawing();
    } // End while

    // Main loop
    mainGameLoop();

    // Close
    CloseWindow();

} // End startGame

// End config.cpp
