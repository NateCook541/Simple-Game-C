#include "raylib.h"
#include "config.h"
#include "screens.h"
#include "gameplay.h"
#include "animals.h"
#include "campingItems.h"
#include <iostream>
#include <vector>

// Global variable declarations
int playerHealth = 100; // (TESTING)
int playerHunger = 100;
int playerThirst = 100;
int playerMoney = 100;
int daysPassed = 0;
std::vector<Animal*> animalInventory;
std::vector<CampingItems> itemsInventory;

// Functions

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
