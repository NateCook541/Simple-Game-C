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
std::vector<CampingItems*> itemsInventory;
std::vector<Consumables*> consumablesInventory;

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

int getInventoryLimit(CampingItems& smallBackPack, CampingItems& largeBackPack) {
    if (largeBackPack.getOwned()) {
        return 15;
    }
    else if (smallBackPack.getOwned()) {
        return 10;
    }
    else {
        return 5;
    }
} // End getInventoryLimit

bool returnInventoryLimit(CampingItems& smallBackPack, CampingItems& largeBackPack) {
    int current = animalInventory.size();
    int maxCapacity = getInventoryLimit(smallBackPack, largeBackPack);
    return current >= maxCapacity;
} // End returnInventoryLimit

// End config.cpp
